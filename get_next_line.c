/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:49:48 by sle-huec          #+#    #+#             */
/*   Updated: 2022/02/06 15:51:38 by sle-huec         ###   ########.fr       */
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
	static char	*rd_buf;

	i = 1;
	rd_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read(fd, rd_buf, BUFFER_SIZE);
	//erase this
	printf("----> %s\n", rd_buf);
	//erase this
	

	return (rd_buf);
}
	/*
	while (ft_strchr(rd_buf, '\n'))
	{
		line = 
	}	

	return (line);
}
*/

//MAIN A DELETE
int main()
{
	int fd;
	char *txt;
	fd = open("fichier.txt", O_RDWR);
	// faire une boucle 
	txt = get_next_line(fd);
	printf("%s\n", txt);
}