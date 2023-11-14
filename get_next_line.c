/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:14:39 by aldantas          #+#    #+#             */
/*   Updated: 2023/11/13 18:05:52 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	check_newline(char *s)
{
	int	i;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i++] == '\n')
			return (i - 1);
	}
	return (0);
}

char	*handle_remaining(char *remaining, char *buffer)
{
	char	*join;
	join = ft_strjoin(remaining, buffer);
	return (join);
}

char	*get_line(int fd, char *str)
{	
	char *line;
	int	newline;

	newline = 0;
	read(fd, str, BUFFER_SIZE);
	if ((newline = check_newline(str)) != 0)
	{
		line = ft_substr(str, 0, newline);
	}
	else
		line	= ft_substr(str, 0, BUFFER_SIZE);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*reads_rest;
	char		*line;
	char		*
	int			newline;

	if (fd < 0 | BUFFER_SIZE < 0)
		return (NULL);
	newline = 0;
	line = malloc(sizeof(char) * BUFFER_SIZE);
	line = get_line(fd, line);
	newline = check_newline(line);
	reads_rest += newline;
	return	(line);
}
