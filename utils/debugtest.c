#include "debugtest.h"

void	dprint(const char *str, int color)
{
	printf("\033[1;9%dm", color);

	printf("%s", str);// str

	printf("\033[0m\n");
}
