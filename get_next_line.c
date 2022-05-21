#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	line[10];
	int		size;
	int		timeout;

	if (fd < 0)
		return (0);
	timeout = 15;
	size = 1;
	while (size && timeout)
	{
		size = read(fd, line, 10);
		//line[size] = '\0';
		printf("==========\n");
		printf("line ==> %s\n", line);
		-- timeout;
		printf("size ==> %d\n", size);
	}
	return (0);
	//return (line);
}
