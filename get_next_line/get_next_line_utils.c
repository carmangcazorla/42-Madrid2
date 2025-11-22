/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:32:10 by carmenga          #+#    #+#             */
/*   Updated: 2025/11/02 17:32:15 by carmenga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char    *ft_strdup(const char *src)
{
        int             i;
        char    *dup;

        i = 0;
        while (src[i])
        {
                i++;
        }
        dup = malloc(i + 1);
        if (!dup)
        {
                return (NULL);
        }
        i = 0;
        while (src[i])

        {
                dup[i] = src[i];
                i++;
        }
        dup[i] = '\0';
        return (dup);
}

size_t  ft_strlen(const char *s)
{
        int     len;

        len = 0;
        while (s[len] != 0)
        {
                len++;
        }
        return (len);
}

char    *ft_strchr(const char *s, int c)
{
        int     i;

        i = 0;
        while (s[i] != '\0')
        {
                if (s[i] == (char) c)
                        return ((char *)&s[i]);
                i++;
        }
        if ((char)c == '\0')
                return ((char *)&s[i]);
        return (0);
}

static char     *ft_strncpy(char *dest, char *src, int n)
{
        int     i;

        i = 0;
        while (i < n && src[i] != '\0')
        {
                dest[i] = src[i];
                i++;
        }
        while (i < n)
        {
                dest[i] = '\0';
                i++;
        }
        return (dest);
}

char    *ft_strjoin(char *s1, char *s2)
{
        int             len1;
        int             len2;
        char    *str;

        if (!s1 || !s2)
                return (NULL);
        len1 = ft_strlen(s1);
        len2 = ft_strlen(s2);
        str = (char *)malloc(len1 + len2 + 1);
        if (!str)
                return (NULL);
        ft_strncpy(str, (char *)s1, len1);
        ft_strncpy(str + len1, (char *)s2, len2);
        str[len1 + len2] = '\0';
        free(s1);
        return (str);
}
