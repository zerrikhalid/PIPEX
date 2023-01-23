/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 04:25:28 by kzerri            #+#    #+#             */
/*   Updated: 2023/01/23 13:46:44 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../libft/libft.h"

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
	t_pipex_b	p;
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
