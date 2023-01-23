/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzerri <kzerri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:22:38 by kzerri            #+#    #+#             */
/*   Updated: 2023/01/22 08:25:34 by kzerri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!haystack || !needle)
		return (1);
	if (len == 0 && !haystack)
		return (1);
	if (*(needle) == '\0')
		return (1);
	while (*(haystack + i) && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] && (i + j < len))
			j++;
		if (*(needle + j) == '\0')
			return (0);
		i++;
	}
	return (1);
}
