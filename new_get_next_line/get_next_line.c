/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:14:56 by aldantas          #+#    #+#             */
/*   Updated: 2023/11/13 17:14:57 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*ft_check_new_line(const char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return ((char *)s);
		s++;
	}
	return (0);
}

static char	*get_line(int fd, char *backup)
{
  char *buff[BUFFER_SIZE];
  char *line;
  int   ret;

  ret = 1;
  if (backup)
    add_node_in_list(); // adicionar add list
  while (ret > 0)
  {
    
  }
  return (line);
}


char	*get_next_line(int fd)
{
  static char *backup_line = NULL;
  char *ret_line;

  ret_line = get_line(fd, backup_line);
  
}
