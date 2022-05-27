# include "debugtest.h"
#include "get_next_line.h"

#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fileDescriptor;

	int		timeout;
	char	*file;

	line = "a";

	timeout = 7;
	file = "files/little";
	// timeout = 25;
	// file = "files/medium";
	// timeout = 250;
	// file = "files/bigger";
	// file = "get_next_line.h";

	fileDescriptor = open(file, O_RDONLY);

	while (line && timeout)
		{
		line = get_next_line(fileDescriptor);
		free(line);
		timeout--;
	}
	if (!timeout)
		dprint("TIMEOUT", YELLOW);
	close(fileDescriptor);
	return (0);
}
