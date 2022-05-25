# include "debug.h"
#include "get_next_line.h"

// Function 01


// Function 02 --> update residue


// Function 03 --> read file
char	*ft_read_file(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*text;
	size_t	size;
	int timeout = 15;

	text = NULL;
	size = 0;
	while (!ft_strchr(buffer, '\n'))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = '\0';
		printf("SIZE - %zu ++ buff - %s\n", size, buffer);
		if (!size)
			return (NULL);
		text = ft_strjoin(text, buffer);
		printf("text - %s\n", text);
		timeout--;
		printf("AKI\n");
	}
	return (NULL);
}

// Function 04 --> complete line


// Function 05
char	*get_next_line(int fd)
{
	char		*line;
	char		*content;
	//static char	residue[BUFFER_SIZE];

	// line receives residue
	line = NULL;

	//	read file - put it in content
	content = ft_read_file(fd);

	//	complete line

	//	update residue

	return (line);
}
