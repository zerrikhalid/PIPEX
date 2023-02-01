#include "pipex_bonus.h"
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

void	get_fd_file(int sig, char **av, int *start)
{
	int	fd;

	if (sig == 0)
	{
		*start = 2;
		fd = open(av[1], O_RDONLY, 0644);
		dup2(fd, 0);
	}
	else if (sig == 1)
	{
		*start = 3;
		fd = open(av[1], O_CREAT | O_RDWR, 0644);
		dup2(fd, 1);
	}
	else
	{
		fd = open(av[1], O_CREAT | O_APPEND, 0644);
		dup2(fd, 1);
	}
	if (fd < 0)
	{
		perror(av[1]);
		exit(1);
	}
}

void	mult_pipe(char **av)
{
	t_pipex_bonus	var;

	if(pipe(var.fd) < 0)
		exit(1);
	var.pid = fork();
	if (var.pid == -1)
		exit(1);
	if (!var.pid)
	{
		close(var.fd[0]);
		dup2(var.fd[1], 1);
		ft_exec();
	}
	
}

int main(int ac, char **av, char **env)
{
	t_pipex_bonus   vars;

	while (ac < 5)
		errors();
	if (!(ft_strnstr(av[0], "here_doc", 8)))
	{

	}
	else
		get_fd_file(0, av, &vars.start);
	while (vars.start < ac - 2)
		mult_pipes(av[vars.start++]);
}