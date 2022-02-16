#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
//#include "get_next_line.h"
// erase this
#include <stdio.h>
#include <fcntl.h>
// erase this

char *ft_substr(char *s, int start, int len)
{
	int i;

	i = 0;
	char *temp = malloc(sizeof(*s) * (len + 1));
	if (!temp)
		return (NULL);
	while (i < len && s[start + i])
	{
		temp[i] = s[start + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char *ft_strcpy(char *dst, char *src)
{
	unsigned int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int ft_strchr(char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
		if (s[i] == 0 && (char)c == 0)
				return (i);
		return (-1);
}

size_t  ft_strlen(char *str)
{
		size_t  i;

		i = 0;
		while (str[i] != '\0')
		{
				i++;
		}
		return (i);
}

char *get_next_line(int fd)
{
	char			*line;
	char			*tmp;
	static char		*save;
	unsigned int	i;
	int				len;
	int				ret;
	int				finish;

	i = 1 + !!save;
	finish = 0;
	line = save;
	save = 0;
	
	while (finish == 0)
	{
		if (line != NULL && ft_strchr(line, '\n') != -1)
		{
			finish = 1;
			ret = ft_strchr(line, '\n');
			if (line[ret + 1]) 
			{
				len = ft_strlen(&line[ret + 1]);
				save = ft_substr(line, ret + 1, len);
			}			
			line[ret + 1] = '\0';
			return (line);
		}
		tmp = line;
		len = 0;
		line = malloc(sizeof(char) * (BUFFER_SIZE * i) + sizeof(char));
		if (!line)
			return (NULL);
		if (tmp != NULL)
		{
			ft_strcpy(line, tmp);
			len = ft_strlen(line);
		}
		ret = read(fd, line + len, BUFFER_SIZE);
		line[ret + len] = '\0';
		if (ret == 0 && ft_strlen(line) == 0)
			return (NULL);
		else if (ret == 0)
			return (line);	
		i++;
	}
	return (line);
}

int main()
{
	int fd;
	char *line;
	fd = open("fichier.txt", O_RDWR);
	while (1) 
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
			if (line == NULL)
				break;
	}
}