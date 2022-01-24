/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:22:32 by sle-huec          #+#    #+#             */
/*   Updated: 2022/01/24 19:03:58 by sle-huec         ###   ########.fr       */
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

size_t  ft_strlen(const char *str)
{
        size_t  i;

        i = 0;
        while (str[i] != '\0')
        {
                i++;
        }
        return (i);
}

char    *ft_strjoin(char *s1, char *s2)
{
        char    *new_str;
        int     size;
        int     idx_s1;  

        idx_s1 = ft_strlen(s1)
        size = (idx_s1 + ft_strlen(s2) + 1);
        new_str = (char *)malloc(sizeof(char) * size);
        if (!new_str)
                return (0);
        new_str = ft_memmove(new_str, s1, ft_strlen(s1));
        new_str = ft_memmove(&new_str[idx_s..1], s2, ft_strlen(s2));
        new_str[size - 1] = '\0';
        return (new_str);
}