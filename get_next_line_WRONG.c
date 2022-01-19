/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_WRONG.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:21:55 by sle-huec          #+#    #+#             */
/*   Updated: 2022/01/19 15:51:34 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"
// erase this
#include <stdio.h>
#include <fcntl.h>
// erase this

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	static int	ret;
	static char	buf[BUFFER_SIZE +1];

	i = 0;
	ret = read(fd, buf, BUFFER_SIZE);
	while (buf[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	ft_memmove(line, buf, i);
	line[i] = '\0';
	ret -= i;
	i++;
	ft_memmove(buf, buf + i, ret);
	//
	// printf("%.*s\n",ret , buf);
	//
	return (line);
}

// MAIN A DELETE
int main()
{
	int fd;
	char *line;
	fd = open("fichier.txt", O_RDWR);
	// faire une boucle 
	line = get_next_line(fd);
	printf("%s\n", line);
		// free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
		// free(line);
	line = get_next_line(fd);
	printf("%s\n", line);
		// free(line);
}