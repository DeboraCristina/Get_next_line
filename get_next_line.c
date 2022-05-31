/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:23:26 by desilva           #+#    #+#             */
/*   Updated: 2022/05/31 19:55:35 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_update_residue(char *content, char *dest)
{
	int	len_content;
	int	index_content;

	if (content)
	{
		index_content = 0;
		len_content = (int) ft_strlen(content);
		while (content[index_content] && content[index_content] != '\n')
			index_content++;
		if (content[index_content] == '\n')
			index_content++;
		if (BUFFER_SIZE > index_content)
			ft_bzero(dest, index_content);
		else
			ft_bzero(dest, BUFFER_SIZE + 1);
		ft_strlcpy(dest, content + index_content, len_content);
	}
	else
		dest[0] = '\0';
}

char	*ft_read_file(int fd)
{
	char	*buffer;
	char	*text;
	int		size;
	char	*temp;

	text = NULL;
	buffer = (char *) malloc(BUFFER_SIZE + 1);
	buffer[0] = '\0';
	while (!ft_strchr(buffer, '\n'))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size <= 0)
			break ;
		buffer[size] = '\0';
		temp = text;
		text = ft_strjoin(temp, buffer);
		free(temp);
		if (!text)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (text);
}

char	*ft_complete_line(char *oldline, char *content)
{
	int		i;
	char	*newline;
	char	*cont_line;

	i = 0;
	if (!content && !ft_strlen(oldline))
		return (NULL);
	if (!content)
		return (oldline);
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	cont_line = (char *) malloc(i + 1);
	if (!cont_line)
		return (NULL);
	ft_strlcpy(cont_line, content, i + 1);
	if (!ft_strlen(oldline))
		return (cont_line);
	newline = ft_strjoin(oldline, cont_line);
	free(cont_line);
	if (!newline)
		return (NULL);
	return (newline);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*content;
	char		*freeline;
	static char	residue[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	line = ft_complete_line(line, residue);
	freeline = line;
	if (!ft_strchr(line, '\n'))
	{
		content = ft_read_file(fd);
		line = ft_complete_line(line, content);
		if (freeline != line)
			free(freeline);
	}
	else
	{
		content = (char *) malloc(BUFFER_SIZE + 1);
		ft_strlcpy(content, residue, BUFFER_SIZE + 1);
	}
	ft_update_residue(content, residue);
	free(content);
	return (line);
}
