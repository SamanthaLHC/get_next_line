/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:22:32 by sle-huec          #+#    #+#             */
/*   Updated: 2022/01/16 19:42:41 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void    *ft_memmove(char *dest, char *src, int n)
{
    int         i;

    if (dest == NULL && src == NULL)
        return (NULL);
    i = 0;
    if (src < dest)
    {
        while (n > 0)
        {
            dest[n - 1] = src[n - 1];
            n--;
        }
        return (dest);
    }
    while (i < n)
    {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}

