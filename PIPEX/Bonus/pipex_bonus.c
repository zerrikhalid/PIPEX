/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 08:29:29 by kzerri            #+#    #+#             */
/*   Updated: 2023/01/23 14:02:20 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

void	p_execute(char *av, char **env)
{
	char	**args;
	char	*path;

	args = ft_split(av, ' ');
	if (access(args[0], F_OK | X_OK) == 0)
		path = args[0];
	else
		path = get_path(args[0], env);
	if (execve(path, args, NULL) == -1)
	{
		perror("Error executing command ");
		exit(1);
	}
}

void	errors(int sig)
{
	ft_putendl_fd("Bad Arguments!", 2);
	ft_putendl_fd("./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2", 2);
	exit(1);
}

int	get_fd(char *av,int sig)
{
	int	fd;

	if (sig == 0)
		fd = open(av, O_RDONLY, 0644);
	else
		fd = open(av, O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}

int	main(int ac, char **av, char **env)
{
	t_pipex_bonus p;
	
	if (ac < 5)
		errors(0);
	if (!ft_strnstr(av[1], "here_doc", 8))
		ft_putendl_fd("Please handle this shit later", 2);
	p.p_fd = (int **)malloc(sizeof(int*) * (ac - 3));
	p.i = 0;
	while (p.i < ac - 4)
	{
		if (pipe(p.p_fd[p.i]) < 0)
			exit(EXIT_FAILURE);
		p.i++;
	}
	p.i = 0;
	while (p.i < ac - 3)
	{
		p.pid = fork();
		if (p.pid < 0)
			exit(EXIT_FAILURE);
		if (p.pid == 0)
		{
			if (p.i == 0)
			{
				p.fd = get_fd(av[1], 0);
				if (p.fd < 0)
				{
					perror(av[1]);
					exit(1);
				}
				close(p.p_fd[p.i][0]);
				dup2(p.fd, 0);
				dup2(p.p_fd[p.i], 1);
			}
		}
		else if (p.i == ac - 4)
		{
			p.fd = get_fd(av[ac - 1], 1);
			if (p.fd < 0)
			{
				perror(av[ac - 1]);
				exit(1);
			}
			close(p.p_fd[p.i][1]);
			dup2(p.fd, 1);
			dup2(p.p_fd[p.i - 1], 0);
			p.j = 0;
			while (p.j < ac - 4)
			{
				close(p.p_fd[p.j - 1][0]);
				close(p.p_fd[p.j - 1][0]);
				p.j++;
			}
			execute_process(av[p.i + 2], env);
		}
		else
		{
			dup2(p.p_fd[p.i - 1][0], 0);
			dup2(p.p_fd[p.i][1], 1);
			p.k = 0;
			while (p.k < ac - 4)
			{
				close(p.p_fd[p.j][0]);
				close(p.p_fd[p.j][1]);
			}
			execute_process(av[p.i + 2], env);
		}
		p.i++;
	}
}