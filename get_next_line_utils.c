/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:23:17 by desilva           #+#    #+#             */
/*   Updated: 2022/05/30 21:54:37 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Function 01
size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	if (str)
	{
		while (str[c])
			c++;
	}
	return (c);
}

// Function 02
char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	l;

	i = 0;
	l = c;
	while (s[i])
	{
		if (l == s[i])
			return ((char *) s + i);
		i++;
	}
	if (!l)
		return ((char *) s + i);
	return (NULL);
}

// Function 03
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sj;
	int		lens1;
	int		lens2;
	int		count;

	lens1 = ft_strlen((char *) s1);
	lens2 = ft_strlen((char *) s2);
	sj = (char *) malloc(lens1 + lens2 + 1);
	count = 0;
	if (!sj)
		return (0);
	while (s1 && *s1)
	{
		sj[count] = *s1++;
		count++;
	}
	while (s2 && *s2)
	{
		sj[count] = *s2++;
		count++;
	}
	sj[count] = 0;
	return (sj);
}

// Function 04
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (!dst || !src)
		return (0);
	if (size)
	{
		while (src[index] && index < size - 1)
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = 0;
	}
	while (src[index])
		index++;
	return (index);
}

// Function 05
void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	c;

	str = (char *) s;
	c = 0;
	while (c++ < n)
		*str++ = '\0';
}
