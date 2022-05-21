#include "../hubgnl/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;
	char	*res;

	fd = open("test_withtext", O_RDONLY);
	printf("file descriptor ==> %d\n", fd);

	printf("Mostrando resultado\n");
	res = get_next_line(fd);
	if (res)
		printf("%s\n", res);
	else
		printf("NULL\n");
	close(fd);

	fd = open("test_notext", O_RDONLY);
	printf("file descriptor ==> %d\n", fd);

	printf("Mostrando resultado\n");
	res = get_next_line(fd);
	if (res)
		printf("%s\n", res);
	else
		printf("NULL\n");
	close(fd);

	return (0);
}
