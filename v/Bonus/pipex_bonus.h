/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 08:29:27 by kzerri            #+#    #+#             */
/*   Updated: 2023/02/04 04:24:29 by kzerri           ###   ########.fr       */
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
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>

typedef struct s_pipex_bonus
{
	int		start;
	int		fd[2];
	int		pid;
	char	*written;
}t_pipex_bonus;

typedef struct s_pipex_b
{
	char	**paths;
	char	*sub_path;
	char	*p_exec;
}t_pipex_b;

void	ft_exec(char *av, char **env);
void	get_fd_file(int sig, char *av, int *start);
void	mult_pipe(char *av, char **env);
char	*get_path(char *command, char **env);
char	**get_env(char *p_index);
void	errors(int sig);
void	ft_here_doc(char *av);

#endif
