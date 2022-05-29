# include "debugtest.h"
#include "get_next_line.h"

#include <fcntl.h>
int	ft_strncmp(const char *s1, const char *s2, size_t limit)
{
	size_t	count;

	count = 0;
	while ((s1[count] || s2[count]) && count < limit)
	{
		if (s1[count] != s2[count])
			return ((unsigned char) s1[count] - (unsigned char) s2[count]);
		++count;
	}
	return (0);
}

void	gnl(int n)
{
	char	*line;
	int		fileDescriptor;

	int		timeout;
	int		test;;
	char	*file;

	test = n; // 1 - 5

	switch (test)
	{
		case 1:
			timeout = 10;
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
		case 5:
			timeout = 2;
			file = "files/no_breakline";
			break ;
		default:
			timeout = 0;
			dprint("NO FILE\n", RED);
	}

	fileDescriptor = open(file, O_RDONLY);

	while (timeout)
	{
		line = get_next_line(fileDescriptor);
		if (line)
		{
			printf("%s", line);
			free(line);
		}
		else
		{
			dprint("NULL\n", PURPLE);
			break ;
		}
		timeout--;
	}
	if (!timeout)
		dprint("+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\nTIMEOUT\n+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n", YELLOW);
	close(fileDescriptor);
}
void	trifilestest(int n)
{
	char	*line;
	int		fileDescriptor;

	int		timeout;
	char	*file[] = {"files/triFiles/41_no_nl", "files/triFiles/41_with_nl", "files/triFiles/42_no_nl", "files/triFiles/42_with_nl", "files/triFiles/43_no_nl", "files/triFiles/43_with_nl", "files/triFiles/alternate_line_nl_no_nl", "files/triFiles/alternate_line_nl_with_nl", "files/triFiles/big_line_no_nl", "files/triFiles/big_line_with_nl", "files/triFiles/empty", "files/triFiles/multiple_line_no_nl", "files/triFiles/multiple_line_with_nl", "files/triFiles/multiple_nlx5", "files/triFiles/nl"};

	timeout = 11;
	//printf("", );
	dprint("file --> ", CYAN);
	dprint(file[n], CYAN);
	dprint("\n", CYAN);
	fileDescriptor = open(file[n], O_RDONLY);

	while (timeout)
	{
		line = get_next_line(fileDescriptor);
		if (line)
		{
			printf("%s", line);
			free(line);
		}
		else
		{
			dprint("NULL\n", PURPLE);
			break ;
		}
		timeout--;
	}
	if (!timeout)
		dprint("+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\nTIMEOUT\n+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*\n", YELLOW);
	close(fileDescriptor);
}
int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!ft_strncmp(argv[2], "m", 1))
		gnl(atoi(argv[1]));
	else if (!ft_strncmp(argv[2], "t", 1))
		trifilestest(atoi(argv[1]));
	return (0);
}
