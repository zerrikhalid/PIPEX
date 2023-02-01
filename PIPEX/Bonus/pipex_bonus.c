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
