/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 04:25:28 by kzerri            #+#    #+#             */
/*   Updated: 2023/02/05 02:11:54 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../libft/libft.h"

void	get_fd_file(int sig, char *av, int *start)
{
	int	fd;

	if (sig == 0)
	{
		*start = 2;
		fd = open(av, O_RDONLY, 0644);
		dup2(fd, 0);
	}
	else if (sig == 1)
	{
		fd = open(av, O_CREAT | O_RDWR | O_TRUNC, 0644);
		dup2(fd, 1);
	}
	else
	{
		*start = 3;
		fd = open(av, O_CREAT | O_RDWR | O_APPEND, 0644);
		dup2(fd, 1);
	}
	if (fd < 0)
	{
		perror(av);
		exit(1);
	}
}

void	errors(int sig)
{
	if (sig == 0)
	{
		ft_putendl_fd("Bad Arguments!", 2);
		ft_putendl_fd("./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2", 2);
	}
	else
	{
		ft_putendl_fd("Bad Arguments!", 2);
		ft_putendl_fd("./pipex here_doc LIMITER cmd cmd1 file", 2);
	}	
	exit(1);
}

char	**get_env(char *p_index)
{
	char	*sub;
	char	**splited;

	sub = ft_strchr(p_index, '/');
	splited = ft_split(sub, ':');
	return (splited);
}

char	*get_path(char *command, char **env)
{
	t_pipex_b	p;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			p.paths = get_env(env[i]);
			break ;
		}
		i++;
	}
	while (p.paths[j])
	{
		p.sub_path = ft_strjoin(p.paths[j], "/");
		p.p_exec = ft_strjoin(p.sub_path, command);
		if (access(p.p_exec, F_OK | X_OK) == 0)
			return (free(p.sub_path), free_all(p.paths), p.p_exec);
		j++;
		free(p.sub_path);
	}
	return (NULL);
}
