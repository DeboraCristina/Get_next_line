/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 05:25:07 by desilva           #+#    #+#             */
/*   Updated: 2022/05/31 05:25:21 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sj;
	int		count;
	int		i;

	sj = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	count = 0;
	i = 0;
	if (!sj)
		return (0);
	while (s1 && s1[count])
	{
		sj[count] = s1[count];
		count++;
	}
	while (s2 && s2[i])
	{
		sj[count] = s2[i];
		count++;
		i++;
	}
	sj[count] = 0;
	return (sj);
}

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

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	c;

	str = (char *) s;
	c = 0;
	while (c++ < n)
		*str++ = '\0';
}
