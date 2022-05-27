#ifndef DEBUG
# define DEBUG
# include <stdio.h>

typedef enum{
	BLACK,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	PURPLE,
	CYAN,
	WHITE
}	t_color;

void	dprint(const char *str, int color);
void	dsprint(const char *s1, const char *s2, int color);

#endif
