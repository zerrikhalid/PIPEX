/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:18:01 by kzerri            #+#    #+#             */
/*   Updated: 2023/02/05 02:19:00 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

void	ft_exec(char *av, char **env)
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
		free_all(args);
		exit(1);
	}
}

void	mult_pipe(char *av, char **env)
{
	t_pipex_bonus	var;

	if (pipe(var.fd) < 0)
		exit(1);
	var.pid = fork();
	if (var.pid == -1)
		exit(1);
	if (!var.pid)
	{
		close(var.fd[0]);
		dup2(var.fd[1], 1);
		ft_exec(av, env);
	}
	else
	{
		close(var.fd[1]);
		dup2(var.fd[0], 0);
	}
	close(var.fd[0]);
	close(var.fd[1]);
}

void	ft_stdin(char *av, int fd[2])
{
	t_pipex_bonus	var;

	close(fd[0]);
	while (1)
	{
		write(1, "here_doc>", 9);
		var.written = get_next_line(0);
		av = ft_strjoin(av, "\n");
		if (var.written != NULL)
		{
			if (!(ft_strncmp(var.written, av, ft_strlen(var.written))))
			{
				free(var.written);
				exit(0);
			}
		}
		else
			exit(1);
		ft_putstr_fd(var.written, fd[1]);
		free(var.written);
	}
}

void	ft_here_doc(char *av)
{
	t_pipex_bonus	var;

	if (pipe(var.fd) < 0)
		exit(1);
	var.pid = fork();
	if (!var.pid)
		ft_stdin(av, var.fd);
	else
	{
		close(var.fd[1]);
		dup2(var.fd[0], 0);
		wait(0);
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipex_bonus	vars;

	if (ac < 5 && (ft_strncmp("here_doc", av[1], 8)))
		errors(0);
	if (!(ft_strncmp("here_doc", av[1], 8)) && av[1][8] == '\0')
	{
		if (ac < 6)
			errors(1);
		ft_here_doc(av[2]);
		get_fd_file(2, av[ac - 1], &vars.start);
	}
	else
		get_fd_file(0, av[1], &vars.start);
	while (vars.start < ac - 2)
		mult_pipe(av[vars.start++], env);
	vars.pid = fork();
	if (!vars.pid)
	{
		get_fd_file(1, av[ac - 1], &vars.start);
		ft_exec(av[ac - 2], env);
	}
	else
		waitpid(vars.pid, NULL, 0);
}
