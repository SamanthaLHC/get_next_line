/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:21:55 by sle-huec          #+#    #+#             */
/*   Updated: 2022/01/15 23:18:11 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "get_next_line.h"

//!!!!!!!!!!!!!
#include <stdio.h>
#include <fcntl.h>
// !!!!!!!!!!!

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
	// erase this
	printf("%s\n", line);
	printf("%d\n", ret);
	// erase this ^
	return (line);
}

// MAIN A DELETE
int main()
{
	int fd;
	fd = open("fichier.txt", O_RDWR);
	get_next_line(fd);
}