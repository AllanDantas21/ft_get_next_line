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

static t_list *get_node(t_list **list)
{
    if (!*list)
    {
        *list = (t_list *)malloc(sizeof(t_list));
        if (!*list)
            return (NULL);
        (*list)->data = ft_strdup("");
        (*list)->next = NULL;
    }
    return (*list);
}

static void remove_node(t_list **list)
{
    t_list *temp;

    if (*list)
    {
        temp = *list;
        *list = temp->next;
        free(temp->data);
        free(temp);
    }
}

static char *extract_line(char **data)
{
    char    *newline;
    char    *line;
    char    *temp;

    newline = NULL;
    if (*data)
        newline = ft_strchr(*data, '\n');
    if (newline)
    {
        line = ft_strndup(*data, newline - *data + 1);
        temp = ft_strdup(newline + 1);
        free(*data);
        *data = temp;
    }
    else
    {
        line = ft_strdup(*data);
        free(*data);
        *data = NULL;
    }
    return (line);
}

static int read_fd(int fd, t_list *node)
{
    char    buffer[BUFFER_SIZE + 1];
    char    *temp;
    ssize_t bytes_read;

    while (!ft_strchr(node->data, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            return (bytes_read);
        buffer[bytes_read] = '\0';
        temp = ft_strjoin(node->data, buffer);
        free(node->data);
        node->data = temp;
    }
    return (1);
}

char *get_next_line(int fd)
{
    static t_list *list;
    t_list        *node;
    char          *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    node = get_node(&list);
    if (!node)
        return (NULL);
    if (read_fd(fd, node) == -1)
        return(remove_node(&list), NULL);
    line = extract_line(&(node->data));
    if (!line || !line[0])
    {
        free(line);
        remove_node(&list);
        return (NULL);
    }
    return (line);
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
    while((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}