# include "debug.h"
#include "get_next_line.h"

// Function 01
size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	if (str)
	{
		while (str[c])
			c++;
	}
	return (c);
}

// Function 02
char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	l;

	i = 0;
	l = c;
	while (s[i])
	{
		if (l == s[i])
			return ((char *) s + i);
		i++;
	}
	if (!l)
		return ((char *) s + i);
	return (0);
}

// Function 03
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sj;
	int		count;

	sj = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	count = 0;
	if (!sj)
		return (0);
	if (s1)
	{
		printf("AKI1\n");
		while (*s1)
			sj[count++] = *s1++;
		printf("AKI2\n");
		free((void *) s1);
	}
	if (s2)
	{
		printf("AKI3\n");
		while (*s2)
			sj[count++] = *s2++;
		printf("AKI4\n");
		// free((void *) s2);
	}
	sj[count] = 0;
	return (sj);
}

// Function 04
// Function 05
