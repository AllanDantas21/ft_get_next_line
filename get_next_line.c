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

static char	*get_line(char *buff)
{
	int		i;
	char	*s;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * i + 2);
	if (!s)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
		s[i] = buff[i++];
	if (buff[i] == '\n')
		s[i] = buff[i++];
	s[i] = '\0';
	return (s);
}

static char	*get_backup(char *buff)
{
	char	*s;
	int		i;
	int		c;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (buff[i])
		s[c++] = buff[i++];
	s[c] = '\0';
	free (buff);
	return (s);
}

static char	*get_buffer(int fd, char *backup)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(backup, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		backup = ft_strjoin(backup, buff);
	}
	free (buff);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buffer;
	char		*line;

	if (fd < 0 | BUFFER_SIZE < 0)
		return (0);
	buffer = get_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	backup = get_backup(buffer);
	return	(line);
}
