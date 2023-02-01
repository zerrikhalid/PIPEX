/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 08:29:27 by kzerri            #+#    #+#             */
/*   Updated: 2023/01/23 14:00:40 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
//# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>

typedef struct s_pipex_bonus
{
	int	start;
	int	fd[2];
	int pid;	
}t_pipex_bonus;

typedef struct s_pipex_b
{
	char	**paths;
	char	*sub_path;
	char	*p_exec;
}t_pipex_b;

#endif
