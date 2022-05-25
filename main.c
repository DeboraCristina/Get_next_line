#include "debug.h"
#include "get_next_line.h"

#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fileDescriptor;
	int		timeout;

	timeout = 310;
	line = "a";
	fileDescriptor = open("get_next_line.h", O_RDONLY);
	while (line && timeout)
		{
		line = get_next_line(fileDescriptor);
		free(line);
		timeout--;
	}
	close(fileDescriptor);
	return (0);
}
