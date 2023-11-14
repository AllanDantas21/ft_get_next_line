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

char	*get_backup(char *line)
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

char	*get_line(int fd, char *buff, char *backup)
{	
	char	*line;
	char	*temp;
	int		newline;

	newline = 0;
	read(fd, buff, BUFFER_SIZE);
	if ((newline = check_newline(buff)) != 0)
	{
		line = ft_substr(buff, 0, newline);
	}
	else
		line	= ft_substr(buff, 0, BUFFER_SIZE);
	if (!backup)
		backup = ft_strdup("");
	temp = backup;
	line = ft_strjoin(backup, line); 
	free(temp);
	temp = NULL;
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
	backup = get_backup(line);
	return	(line);
}
