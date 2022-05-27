# include "debugtest.h"
#include "get_next_line.h"

// Function 01

// Function 02 --> update residue
void	ft_update_residue(char *content, char *dest)
{
	int	len_content;
	int	index_content;
	int	index_destiny;

	index_destiny = 0;
	if (content)
	{
		index_content = 0;
		len_content = (int) ft_strlen(content);
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
		while (index_destiny < BUFFER_SIZE + 1)
			dest[index_destiny++] = '\0';
}

// Function 03 --> read file
char	*ft_read_file(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*text;
	int		size;
	char	*temp;

	text = NULL;
	while (!ft_strchr(buffer, '\n'))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size <= 0)
			break ;
		buffer[size] = '\0';
		temp = text;
		text = ft_strjoin(temp, buffer);
		if (!text)
			return (NULL);
		free(temp);
		temp = NULL;
	}
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
	{
		if (ft_strlen(oldline) > 0)
			return (oldline);
		return (NULL);
	}
	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	cont_line = (char *) malloc(i + 1);
	if (!cont_line )
		return (NULL);
	ft_strlcpy(cont_line , content, i + 2);
	if (!oldline)
		return (cont_line);
	newline = ft_strjoin(oldline, cont_line);
	if (!newline )
		return (NULL);
	free(cont_line);
	return (newline);
}

// Function 05
char	*get_next_line(int fd)
{
	char		*line;
	char		*content;
	char		*freeline;
	static char	residue[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	line = ft_complete_line(line, residue);
	freeline = line;
	if (!ft_strchr(line, '\n'))
	{
		content = ft_read_file(fd);
		line = ft_complete_line(line, content);
		free(freeline);
		if (!line)
			return (NULL);
		freeline = NULL;
	}
	else
	{
		content = (char *) malloc(BUFFER_SIZE + 1);
		ft_strlcpy(content, residue, BUFFER_SIZE + 1);
	}
	ft_update_residue(content, residue);
	if (!content)
		return (NULL);
	if (content)
		free(content);
	return (line);
}
