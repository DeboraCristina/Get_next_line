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
	else
		dest[0] = -1;
}

// Function 03 --> read file
char	*ft_read_file(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*text;
	int		size;
	char	*temp;

	text = NULL;
	// buffer = (char *) malloc(BUFFER_SIZE + 1);
	while (!ft_strchr(buffer, '\n'))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size <= 0)
			break ;
		buffer[size] = '\0';
		temp = text;
		text = ft_strjoin(temp, buffer);
		// dprint("free 01", 2);
		// dprint(temp, 0);
		free(temp);
		temp = NULL;
	}
	// dprint("free 02", 2);
	// free(buffer);
	return (text);
}

// Function 04 --> complete line
char	*ft_complete_line(char *oldline, char *content)
{
	int		i;
	char	*newline;
	char	*cont_line;

	if (!content && !oldline)
		return (NULL);
	else if (!content)
		return (NULL);
	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	cont_line = (char *) malloc(i + 1);
	ft_strlcpy(cont_line , content, i + 2);
	if (!oldline)
		return (cont_line);
	newline = ft_strjoin(oldline, cont_line);
	// dprint("free 03", 2);
	free(cont_line);
	return (newline);
}

// Function 05
char	*get_next_line(int fd)
{
	char		*line;
	char		*content;
	static char	residue[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1) // line receives residue
		return (NULL);
	line = NULL;
	line = ft_complete_line(line, residue);

	//	read file - put it in content
	if (!line)
		content = ft_read_file(fd);
	else
	{
		content = (char *) malloc(BUFFER_SIZE + 1);
		ft_strlcpy(content, residue, BUFFER_SIZE + 1);
	}
	line = ft_complete_line(line, content);
	ft_update_residue(content, residue);

	// dprint("free 04", 2);
	if (content)
		free(content);
	return (line);
}
