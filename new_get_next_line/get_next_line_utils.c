/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:14:56 by aldantas          #+#    #+#             */
/*   Updated: 2023/11/13 17:14:57 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

char    *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return (NULL);
}

char    *ft_strdup(const char *s)
{
    char    *copy;
    size_t  len;
    size_t  i;

    len = 0;
    while (s[len])
        len++;
    copy = (char *)malloc(len + 1);
    if (!copy)
        return (NULL);
    i = 0;
    while (i < len)
    {
        copy[i] = s[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

char    *ft_strndup(const char *s, size_t n)
{
    char    *copy;
    size_t  i;

    copy = (char *)malloc(n + 1);
    if (!copy)
        return (NULL);
    i = 0;
    while (i < n && s[i])
    {
        copy[i] = s[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

char    *ft_strjoin(const char *s1, const char *s2)
{
    char    *joined;
    size_t  len1;
    size_t  len2;
    size_t  i;

    if (!s1)
        s1 = "";
    if (!s2)
        s2 = "";
    len1 = 0;
    while (s1[len1])
        len1++;
    len2 = 0;
    while (s2[len2])
        len2++;
    joined = (char *)malloc(len1 + len2 + 1);
    if (!joined)
        return (NULL);
    i = -1;
    while (++i < len1)
        joined[i] = s1[i];
    i = -1;
    while (++i < len2)
        joined[len1 + i] = s2[i];
    joined[len1 + len2] = '\0';
    return (joined);
}
