# include "debugtest.h"
#include "get_next_line.h"

#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	*line;
	int		fileDescriptor;

	int		timeout;
	int		test;;
	char	*file;

	line = "a";
	if (argc < 2)
	{
		dprint("no arg", 1);
		return (0);
	}
	test = atoi(argv[1]); // 1 - 4

	switch (test)
	{
		case 1:
			timeout = 15;
			file = "files/little";
			break ;
		case 2:
			timeout = 25;
			file = "files/medium";
			break ;
		case 3:
			timeout = 250;
			file = "files/bigger";
			break ;
		case 4:
			timeout = 40;
			file = "get_next_line.h";
			break ;
		default:
			dprint("ERRO", RED);
	}

	fileDescriptor = open(file, O_RDONLY);

	while (line && timeout)
	{
		line = get_next_line(fileDescriptor);
		if (line)
			printf("%s", line);
		else
			dprint("NULL", PURPLE);
		free(line);
		timeout--;
	}
	if (!timeout)
		dprint("+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\nTIMEOUT\n+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*", YELLOW);
	close(fileDescriptor);
	return (0);
}
