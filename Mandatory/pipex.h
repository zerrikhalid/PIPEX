/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 04:16:00 by kzerri            #+#    #+#             */
/*   Updated: 2023/02/05 01:56:32 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <errno.h>

typedef struct s_pipex
{	
	pid_t	pid1;
	pid_t	pid2;
	int		p_fd[2];
	int		status;
	char	**paths;
	char	*sub_path;
	char	*p_exec;
}t_pipex;

void	p_execute(char *av, char **env);
void	errors(void);
void	p_first_child(char **av, int *p_fd, char **env);
void	p_second_child(char **av, int *p_fd, char **env);
int		get_file(char *file, int sig);
char	**get_env(char *p_index);
char	*get_path(char *command, char **env);

#endif