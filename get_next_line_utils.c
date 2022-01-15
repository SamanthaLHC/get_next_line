/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:22:32 by sle-huec          #+#    #+#             */
/*   Updated: 2022/01/15 23:18:03 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void    *ft_memcpy(char *dest, char *src, int n)
{
    int         i;

    if (dest == NULL && src == NULL)
        return (NULL);
    i = 0;
    while (i < n)
    {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}