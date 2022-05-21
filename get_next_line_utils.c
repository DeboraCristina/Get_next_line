/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:28:29 by desilva           #+#    #+#             */
/*   Updated: 2022/05/22 01:28:31 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// function 01
int	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	if (!s)
		return (0);
	while (s[c])
		c++;
	return (c);
}

// function 02
char	*ft_strjoin(char const *str01, char const *str02)
{
	char	*strjoin;
	int		lenstr01;
	int		lenstr02;
	int		counter;

	lenstr01 = ft_strlen(str01);
	lenstr02 = ft_strlen(str02);
	counter = 0;
	strjoin = (char *) malloc(lenstr01 + lenstr02);
	if (!strjoin)
		return (0);
	if (str01)
		while (*str01)
			strjoin[counter++] = *str01++;
	if (str02)
		while (*str02)
			strjoin[counter++] = *str02++;
	strjoin[counter] = 0;
	return (strjoin);
}

// function 03
char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	l;

	i = 0;
	l = c;
	while (s[i])
	{
		if (l == s[i])
			return ((char *) s + i + 1);
		i++;
	}
	if (!l)
		return ((char *) s + i);
	return (0);
}

// function 04
void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	c;

	str = (char *) s;
	c = 0;
	while (c++ < n)
		*str++ = '\0';
}
