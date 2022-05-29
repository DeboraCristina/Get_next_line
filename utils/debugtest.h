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

#endif
