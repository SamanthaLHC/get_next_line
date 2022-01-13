/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:21:55 by sle-huec          #+#    #+#             */
/*   Updated: 2022/01/13 12:44:19 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// recuperer la line avec le fd 
// gérer les pb du buffer
// malloc pour param 2 de read a l aide de BUFFER_SIZE
//!!!!!!!!!!!!!
#include <stdio.h>
// !!!!!!!!!!!
char	*get_next_line(int fd)
{
	char	*line;
	int		i;
	char	*buf;

	while (line[i] != '\n')
	{
		buf = malloc(sizeof (char) * BUFFER_SIZE + 1);
		if (!buf)
			return (NULL); 
		line = read(fd, buf, BUFFER_SIZE);
		// !!!!!!!!!!!!!
		printf("%s\n", line);
		// !!!!!!!!!!!!
	}
}
// MAIN A DELETE
int main()
{
	int fd;
	
	fd = open("fichier.txt", O_RDONLY); 
	get_next_line(fd);
}