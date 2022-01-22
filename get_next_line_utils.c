/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:22:32 by sle-huec          #+#    #+#             */
/*   Updated: 2022/01/22 15:37:54 by sle-huec         ###   ########.fr       */
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

int ft_strchr(char *s, int c)
{
    int i;

    i = 0;
    while (s[i])
    {
            if (s[i] == (char)c)
                    return (i);
            i++;
        }
        if (s[i] == 0 && (char)c == 0)
                return (i);
        return (-1);
}

int     ft_strlen

char    *ft_strjoin(char *s1, char *s2)
{
        char         *new_str;
        int          size;

        size = (ft_strlen(s1) + ft_strlen(s2) + 1);
        new_str = (char *)malloc(sizeof(char) * size);
        if (!new_str)
                return (0);
        ft_strlcpy(new_str, s1, size);
        ft_strlcat((char *)new_str, s2, size);
        return (new_str);
}