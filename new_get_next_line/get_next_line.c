/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:14:56 by aldantas          #+#    #+#             */
/*   Updated: 2024/11/13 10:39:41 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include "stdio.h"

static int ft_check_new_line(const char *s)
{
	while (*s)
	{
		if (*s && *s == '\n')
			return (1);
		s++;
	}
	return (0);
}

static char *ft_strdup(const char *s)
{
    char *str;
    int i;

    i = 0;
    while (s[i])
        i++;
    str = malloc(sizeof(char) * (i + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (s[i])
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

static char *get_line(t_data *data)
{
    char *buff;
    int ret;
    t_list *node;

    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    ret = 1;
    while (ret > 0)
    {
        ret = read(data->fd, buff, BUFFER_SIZE);
        if (ret <= 0)
            break;
        buff[ret] = '\0';
        add_node_in_list(data, ft_strdup(buff));
        if (ft_check_new_line(buff))
            break;
    }
    return (NULL);
}

char *get_next_line(int fd)
{
    static char *backup_line = NULL;
    t_data data;

    data = (t_data){0};
    data.fd = fd;
    data.head = NULL;
    if (backup_line)
         add_node_in_list(&data, backup_line);
    get_line(&data);
    extract_ret_line(&data);
    backup_line = extract_backup(&data);
    free_all_list(&data);
    return (data.ret_line);
}

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line = NULL;

    fd = open("teste.txt", O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    while(line = get_next_line(fd))
        printf("%s", line);
    return 0;
}
