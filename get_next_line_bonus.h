/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:07:19 by sle-huec          #+#    #+#             */
/*   Updated: 2022/02/21 12:08:37 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_substr(char *s, int start, int len);
char	*ft_strcpy(char *dst, char *src);
int		ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);

#endif