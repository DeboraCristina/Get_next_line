# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"

void	mytest_readcombehavior(void)
{
	char	buff[BUFFER_SIZE];
	int		fd;
	int		size;
	int		next;
	int		timeout;

	next = 1;
	timeout = 50;
	fd = open("littletest", O_RDONLY);
	printf("file decriptor: %d\n", fd);

	while (next && timeout)
	{
		size = read(fd, buff, BUFFER_SIZE);
		buff[size] = 0;

		printf("size ==> |%d|\n", size);
		printf("buff ==> \n |%s|\n", buff);
		ft_bzero(buff, size);

		printf("next? ");
		scanf("%d", &next);
		if (!next)
			break ;
		timeout--;
	}
	printf("end\n");
	close(fd);
}
//	##########################################	//
int	sum(int n)
{
	static int	sum;

	sum = 0;
	sum += n;
	return (sum);
}
void	static_variable(void)
{
	printf("%d\n", sum(5));
	printf("%d\n", sum(5));
	printf("%d\n", sum(5));
}
//	##########################################	//
void	mytest_gnl(void)
{
	int		fd;
	char	*result;
	int		timeout;

	timeout = 50;

	// fd = open("emptytest", O_RDONLY);
	fd = open("littletest", O_RDONLY);
	// fd = open("get_next_line.h", O_RDONLY);
	printf("file descriptor ==> %d\n", fd);

	do
	{
		result = get_next_line(fd);
		if (result)
			printf("%s\n", result);
		else
			printf("NULO\n");
		timeout--;
		free(result);
	}while (result && timeout);
	if (!timeout)
		printf("\033[0;91mTimeout\n");

	close(fd);
}
int	main(void)
{
	// mytest_readcombehavior();
	// static_variable();
	mytest_gnl();
	return (0);
}

