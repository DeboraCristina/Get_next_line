# include "debug.h"
#include "get_next_line.h"

// Function 01


// Function 02 --> update residue


// Function 03 --> read file
char	*ft_read_file(int fd)
{
	char	*buffer;
	char	*text;
	int		size;
	char	*temp;

	text = NULL;
	buffer = (char *) malloc(BUFFER_SIZE + 1);
	while (!ft_strchr(buffer, '\n'))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size <= 0)
			break ;
		buffer[size] = '\0';
		temp = text;
		text = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
	}
	free(buffer);
	return (text);
}

// Function 04 --> complete line


// Function 05
char	*get_next_line(int fd)
{
	char		*line;
	char		*content;
	//static char	residue[BUFFER_SIZE + 1];

	// line receives residue
	line = NULL;

	//	read file - put it in content
	content = ft_read_file(fd);
	printf("content - \n%s", content);

	//	complete line

	//	update residue

	// return (line);
	return (content);
}
