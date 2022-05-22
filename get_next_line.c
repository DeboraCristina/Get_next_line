# include <stdio.h>
#include "get_next_line.h"

char	*ft_readline(char *content)
{
	char	*line;
	int		i;

	if (!content)
		return (0);
	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (!i)
		return (0);
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
	int		size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	size = 1;
	content = 0;
	while (size && !ft_strchr(buff, '\n'))
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size < 0)
			return (0);
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
	printf("\033[1;95mline\n%s\033[0mEND\n", line);
	printf("\033[1;94mcontent\n%s\033[0mEND\n", content);
	return (line);
}
