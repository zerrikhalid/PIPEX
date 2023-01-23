/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:31:14 by kzerri            #+#    #+#             */
/*   Updated: 2023/01/23 04:34:10 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/libft.h"

int	get_file(char *file, int sig)
{
	int	fd;

	if (sig == 0)
		fd = open(file, O_RDONLY, 0644);
	else
		fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
		exit(2);
	return (fd);
}

char	**get_env(char *p_index)
{
	char	*sub;
	char	**splited;

	sub = ft_strchr(p_index, '/');
	splited = ft_split(sub, ':');
	return (free(sub), splited);
}

char	*get_path(char *command, char **env)
{
	t_pipex	p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (!ft_strnstr(env[i], "PATH=", 5))
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
			return (p.p_exec);
		j++;
	}
	return (NULL);
}
