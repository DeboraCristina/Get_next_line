/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desilva <dede-2231@hotmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 05:24:24 by desilva           #+#    #+#             */
/*   Updated: 2022/05/31 05:25:53 by desilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_update_residue(char *content, char *dest)
{
	int	len_content;
	int	index_content;
	int	index_destiny;

	ft_bzero(dest, BUFFER_SIZE + 1);
	if (content)
	{
		index_destiny = 0;
		index_content = 0;
		len_content = (int) ft_strlen(content);
		while (content[index_content] && content[index_content] != '\n')
			index_content++;
		if (content[index_content] == '\n')
			index_content++;
		while (content[index_content] && index_content <= len_content)
		{
			dest[index_destiny] = content[index_content];
			index_destiny++;
			index_content++;
		}
	}
}

char	*ft_read_file(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*text;
	int		size;
	char	*temp;

	text = NULL;
	ft_bzero(buffer, BUFFER_SIZE + 1);
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
			return (NULL);
		temp = NULL;
	}
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
