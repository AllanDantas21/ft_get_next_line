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
#include "stdio.h"

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

static char	*get_line(t_data *data, char *backup)
{
  char buff[100000] = {0};
  char *line = NULL;
  int   ret;

  ret = 1;
  if (backup)
    add_node_in_list(data, backup);
  while (ret > 0)
  {
    ret = read(data->fd, buff, BUFFER_SIZE);
    if (ret == -1)
      return (0);
    add_node_in_list(data, buff);
    if (ft_check_new_line(buff))
      break ;
  }
  return (line);
}

char	*get_next_line(int fd)
{
  static char *backup_line = NULL;
  t_data data;
  
  data = (t_data){0};
  data.fd = fd;
  backup_line = get_line(&data, backup_line);
  extract_ret_line(data.head);
  free_all_list(&data);
  return(data.ret_line);
}

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("teste.txt", O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    close(fd);
    return 0;
}
