#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	line[BUFFER_SIZE];
	int		size;
	int		timeout;
	int		i;

	if (fd < 0)
		return (0);
	size = 1;
	timeout = 150;
	i = 0;
	while (size || !timeout)
	{
		size = read(fd, line, BUFFER_SIZE);
		while (i < size)
		{
			if (line[i] == '\n'|| !line[i])
			i ++;
		}
		-- timeout;
	}
	return (0);
	return (line);
}
