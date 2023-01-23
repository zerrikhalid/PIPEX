/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 04:20:51 by kzerri            #+#    #+#             */
/*   Updated: 2023/01/23 10:55:26 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/libft.h"

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

void	errors(void)
{
	ft_putendl_fd("Bad Arguments!", 2);
	ft_putendl_fd("./pipex file1 cmd1 cmd2 file2", 2);
	exit(1);
}

void	p_first_child(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = get_file(av[1], 0);
	if (fd < 0)
	{
		perror(av[1]);
		exit(1);
	}
	close(p_fd[0]);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	p_execute(av[2], env);
}

void	p_second_child(char **av, int *p_fd, char **env)
{
	int	fd;

	fd = get_file(av[4], 1);
	if (fd < 0)
	{
		perror(av[4]);
		exit(1);
	}
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	p_execute(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	p;

	if (ac != 5)
		errors();
	if (pipe(p.p_fd) == -1)
		exit(EXIT_FAILURE);
	p.pid1 = fork();
	if (p.pid1 == -1)
		exit(EXIT_FAILURE);
	if (p.pid1 == 0)
		p_first_child(av, p.p_fd, env);
	else
	{
		close(p.p_fd[1]);
		p.pid2 = fork();
		if (p.pid2 == 0)
			p_second_child(av, p.p_fd, env);
		else
		{
			waitpid(p.pid1, NULL, 0);
			waitpid(p.pid2, &p.status, 0);
			if (WIFEXITED(p.status))
				exit(WEXIT01STATUS(p.status));
		}
	}
}
