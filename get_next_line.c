# include "debugtest.h"
#include "get_next_line.h"

// Function 01

// Function 02 --> update residue
void	ft_update_residue(char *content, char *dest)
{
	int	len_content;
	int	index_content;
	int	index_destiny;

	if (content)
	{
		index_content = 0;
		len_content = (int) ft_strlen(content);
		index_destiny = 0;
		while (content[index_content] && content[index_content] != '\n') // index_content == \n ou \0
			index_content++;
		index_content++;
		while (content[index_content] && index_content <= len_content)
		{
			dest[index_destiny] = content[index_content];
			index_destiny++;
			index_content++;
		}
		if (dest[index_destiny] != '\0')
			dest[index_destiny] = '\0';
	}
}

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
char	*ft_complete_line(char *oldline, char *content)
{
	char	*newline;
	int		i;
	size_t	linelen;

	if (!content)
		return (oldline);
	i = 0;
	linelen = ft_strlen(oldline);
	while (content[i] && content[i] != '\n')
		i++;
	newline = (char *) malloc(sizeof(char) * linelen + i + 1);
	if (!newline)
		return (NULL);
	newline[i + 1] = '\0';
	while (oldline && linelen)
	{
		dprint("aki", RED);
		newline[linelen] = oldline[linelen];
		linelen--;
	}
	while (i >= 0)
	{
		newline[i] = content[i];
		i--;
	}
	return (newline);
}

// Function 05
char	*get_next_line(int fd)
{
	char		*line;
	char		*content;
	static char	residue[BUFFER_SIZE + 1];

	// line receives residue
	line = NULL;
	line = ft_complete_line(line, residue);
	dprint(line, YELLOW);
	dprint("====================\n", RED);

	//	read file - put it in content
	content = ft_read_file(fd);

	//	complete line
	line = ft_complete_line(line, content);
	dprint(line, WHITE);
	dprint("====================\n", RED);

	//	update residue
	ft_update_residue(content, residue);

	return (line);
}
