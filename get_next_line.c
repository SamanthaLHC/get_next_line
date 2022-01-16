/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:21:55 by sle-huec          #+#    #+#             */
/*   Updated: 2022/01/16 19:03:06 by sle-huec         ###   ########.fr       */
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
	static char	buf[BUFFER_SIZE];

	i = 0;
	ret = read(fd, buf, BUFFER_SIZE);
	while (buf[i] != '\n' && i < BUFFER_SIZE)
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	ft_memcpy(line, buf, i);
	line[i] = '\0';
// buf = ici placer un calcul pour supprimer le debut du buf 
// correspondant a la line
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
		free(line);
}