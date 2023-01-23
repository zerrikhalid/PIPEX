/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 01:13:25 by kzerri            #+#    #+#             */
/*   Updated: 2023/01/22 08:25:53 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define EXIT_NOT_FOUND 127

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

char	*ft_strchr(char *s, int c);
void	ft_putendl_fd(char *str, int fd);
int		ft_strlen(char *str);
char	**ft_split(char const *str, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strnstr(char *haystack, char *needle, size_t len);

#endif