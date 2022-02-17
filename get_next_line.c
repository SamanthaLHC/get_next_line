/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:49:48 by sle-huec          #+#    #+#             */
/*   Updated: 2022/02/17 18:52:59 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
	char			*line;
	char			*tmp;
	static char		*save;
	unsigned int	i;
	int				len;
	int				ret;
	//int				finish;

	i = 1 + !!save;
	//finish = 0;
	line = save;
	save = NULL;
	len = 0;

	//while (finish == 0)
	while (1)
	{
		if (line != NULL && ft_strchr(line, '\n') != -1)
		{
			//finish = 1;
			ret = ft_strchr(line, '\n');
			//len = ft_strlen(&line[ret + 1]);
			save = ft_substr(line, ret + 1, ft_strlen(&line[ret + 1]));
			line[ret + 1] = '\0';
			return (line);
		}
		//line = retour de fonction ligne 36 a 43;
		tmp = line;
		//len = 0;
		line = malloc(sizeof(char) * (BUFFER_SIZE * i + 1));
		if (!line)
			return (NULL);
		//transformer la condition du dessous en len = ft_check(line, tmp);
		if (tmp)
		{
			ft_strcpy(line, tmp);
			free(tmp);
			len = ft_strlen(line);
		}
		//proteger le read si jamais return -1
		ret = read(fd, line + len, BUFFER_SIZE);
		line[ret + len] = '\0';
		if (ret == 0 && line[0] == '\0')
		//if (ret == 0 && ft_strlen(line) == 0)
		{
			free(save);
			free(line);
			return (NULL);
		}
		else if (ret == 0)
			return (line);	
		i++;
	}
	return (line);
}

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
