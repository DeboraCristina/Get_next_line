/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:28:04 by desilva           #+#    #+#             */
/*   Updated: 2022/05/22 01:29:21 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readline(char *content)
{
	char	*line;
	int		i;

	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	i += 1;
	line = (char *) malloc(sizeof(char) * i);
	if (!line)
		return (0);
	line[i--] = 0;
	line[i--] = '\n';
	while (i >= 0)
	{
		line[i] = content[i];
		i--;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char	buff[BUFFER_SIZE];
	char	*content;
	char	*line;
	size_t	size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	size = 1;
	while (size && !ft_strchr(buff, '\n'))
	{
		size = read(fd, buff, BUFFER_SIZE);
		buff[size] = 0;
		content = ft_strjoin(content, buff);
		if (!content)
			return (0);
	}
	ft_bzero(buff, size);
	line = ft_readline(content);
	if (!line)
	{
		free(content);
		return (0);
	}
	content = ft_strchr(content, '\n');
	return (line);
}
