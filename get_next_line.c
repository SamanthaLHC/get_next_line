/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:49:48 by sle-huec          #+#    #+#             */
/*   Updated: 2022/02/19 14:45:17 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"

int	get_save(char **save, char *line)
{
	int		ret;

	if (line != NULL && ft_strchr(line, '\n') != -1)
	{
		ret = ft_strchr(line, '\n');
		*save = ft_substr(line, ret + 1, ft_strlen(&line[ret + 1]));
		line[ret + 1] = '\0';
		return (1);
	}
	return (0);
}

int	increase_buff(char **line, unsigned int i)
{
	char			*tmp;
	int				len;

	len = 0;
	tmp = *line;
	*line = malloc(sizeof(char) * (BUFFER_SIZE * i + 1));
	if (!*line)
		return (-1);
	if (tmp)
	{
		ft_strcpy(*line, tmp);
		free(tmp);
		len = ft_strlen(*line);
	}
	return (len);
}

char	*last_read(char *line)
{
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*save;
	unsigned int	i;
	int				len;
	int				ret;

	i = 1 + !!save;
	line = save;
	save = NULL;
	while (1)
	{
		if (get_save(&save, line))
			return (line);
		len = increase_buff(&line, i);
		if (len == -1)
			return (NULL);
		ret = read(fd, line + len, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		line[ret + len] = '\0';
		if (ret == 0)
			return (last_read(line));
		i++;
	}
	return (line);
}

/*
#include <stdio.h>
#include <fcntl.h>

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
			if (!line)
				break;
	}
}
//*/
