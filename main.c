#include "debug.h"
#include "get_next_line.h"

#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fileDescriptor;
	// int		timeout;

	// timeout = 5;
	fileDescriptor = open("littletest", O_RDONLY);
	line = get_next_line(fileDescriptor);
	free(line);
	close(fileDescriptor);
	return (0);
}
