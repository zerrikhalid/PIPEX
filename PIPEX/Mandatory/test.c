/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:55:30 by kzerri            #+#    #+#             */
/*   Updated: 2023/01/23 12:49:53 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAX_COMMANDS 3

int main(int argc, char **argv)
{
    int i, j;
    int pipes[MAX_COMMANDS - 1][2];
    pid_t pid;

    if (argc < 2) {
        printf("Usage: %s command1 command2 ... commandN\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (i < MAX_COMMANDS - 1) {
        if (pipe(pipes[i]) < 0) {
            perror("pipe");
            exit(EXIT_FAILURE);
        }
		i++;
    }

    for (i = 0; i < MAX_COMMANDS; i++) 
    {
        pid = fork();
        if (pid < 0) 
		{
            perror("fork");
            exit(EXIT_FAILURE);
        } 
		else if (pid == 0) 
		{
            if (i == 0) 
			{
                dup2(pipes[i][1], 1);
                close(pipes[i][0]);
            } 
			else if (i == MAX_COMMANDS - 1) 
			{
                dup2(pipes[i - 1][0], 0);
				
                for (j = 0; j < MAX_COMMANDS - 1; j++) 
				{
                    close(pipes[j][0]);
                    close(pipes[j][1]);
                }
                execvp(argv[i + 1], &argv[i + 1]);
                perror("execvp");
                exit(EXIT_FAILURE);
            } 
			else 
			{
                // Middle commands
                dup2(pipes[i - 1][0], 0);
                dup2(pipes[i][1], 1);
                for (j = 0; j < MAX_COMMANDS - 1; j++) 
				{
                    close(pipes[j][0]);
                    close(pipes[j][1]);
                }
                execvp(argv[i + 1], &argv[i + 1]);
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        }
    }

    // Parent process
    for (i = 0; i < MAX_COMMANDS - 1; i++) {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }

    while (wait(NULL) != -1);

    exit(EXIT_SUCCESS);
}
// void	pipe_exec(char *av, char **env)
// {
// 	t_pipex_bonus p;

// 	if (pipe(p.p_fd) > 0)
// 		perror(EXIT_FAILURE);
// 	p.pid = fork();
// 	if (p.pid < 0)
// 		exit(EXIT_FAILURE);
// 	if (!p.pid)
// 	{
		
// 	}
	
// }
