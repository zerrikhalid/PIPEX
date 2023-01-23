#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_file(int fd, char *buffer);
char	*get_my_line(char *buffer);
size_t	ft_strlength(const char *s);
char	*ft_strjoins(char const *s1, char const *s2);
char	*ft_strchar(const char *s, int c);
char	*ft_strdup(const char *s1);

#endif