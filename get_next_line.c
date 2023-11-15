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

static int	check_newline(char *s)
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

static char	*get_backup(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0')
		return (0);
	backup = ft_substr(line, count + 1, ft_strlen(line));
	if (!backup)
	{
		free(backup);
		backup == NULL;	
	}
	line[count + 1] == '\0';
	return (backup);
}

static char	*concat_backup(char *backup, char *line)
{
	char	*full_line;

	if (!backup)
		backup = ft_strdup("");
	full_line = ft_strjoin(backup, line);
	if(!full_line)
		return (0);
	return (full_line);
}

static char	*get_line(int fd, char *buff, char *backup)
{	
	char	*line;
	int		newline;

	newline = 0;
	read(fd, buff, BUFFER_SIZE);
	if ((newline = check_newline(buff)) != 0)
	{
		line = ft_substr(buff, 0, newline);
	}
	else
		line	= ft_substr(buff, 0, BUFFER_SIZE);
	line = concat_backup(backup, line);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buffer;
	char		*line;

	if (fd < 0 | BUFFER_SIZE < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = get_line(fd, buffer, backup);
	free(buffer);	
	buffer = NULL;
	if (!line)
		return (NULL);
	backup = get_backup(line);
	return	(line);
}
