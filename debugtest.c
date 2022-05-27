#include "debugtest.h"

void	dprint(const char *str, int color)
{
	printf("\033[1;9%dm", color);

	printf("%s", str);// str

	printf("\033[0m\n");
}

void	dsprint(const char *s1, const char *s2, int color)
{
	//cor
	printf("\033[1;9%dm", color);

	printf("%s	-->\n", s1);// s1
	printf("%s", s2);// s2

	//fim
	printf("\033[0m\n");
}
