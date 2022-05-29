# include "debugtest.h"
#include "get_next_line.h"

#include <fcntl.h>

void	gnl(int n)
{
	char	*line;
	int		fileDescriptor;

	int		timeout;
	int		test;;
	char	*file;

	test = n; // 1 - 4

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
			timeout = 0;
			dprint("ERRO", RED);
	}

	fileDescriptor = open(file, O_RDONLY);

	while (timeout != 0)
	{
		line = get_next_line(fileDescriptor);
		if (line)
		{
			printf("%s", line);
			// free(line);
		}
		else
		{
			dprint("NULL", PURPLE);
			break ;
		}
		timeout--;
	}
	if (!timeout)
		dprint("+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\nTIMEOUT\n+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*", YELLOW);
	close(fileDescriptor);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		dprint("no arg", 1);
		return (0);
	}
	gnl(atoi(argv[1]));
	return (0);
}
