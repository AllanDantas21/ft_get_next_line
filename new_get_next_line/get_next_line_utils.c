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
#include "stdio.h"

void extract_ret_line(t_data *data)
{
    t_list *node;
    char *line;
    int len;
    int i;
    int j;

    node = data->head;
    len = 0;
    while (node)
    {
        i = 0;
        while (node->line[i] && node->line[i] != '\n')
        {
            len++;
            i++;
        }
        node = node->next;
    }
    line = malloc(len + 1);
    if (!line)
        return ;
    node = data->head;
    i = 0;
    while (node)
    {
        j = 0;
        while (node->line[j] && node->line[j] != '\n')
        {
            line[i++] = node->line[j++];
        }
        node = node->next;
    }
    line[i] = '\0';
    printf("%s", line);
    data->ret_line = line;
}

/*char *extract_backup()
{
  // extrair o backup
}*/

void free_all_list(t_data *data)
{
    t_list *tmp;

    while (data->head)
    {
        tmp = data->head;
        data->head = data->head->next;
        free(tmp);
    }
}

void add_node_in_list(t_data *data, char *line)
{
    t_list *node;
    t_list *current;

    current = NULL;
    node = malloc(sizeof(t_list));
    if (!node)
        return;
    //printf("line dentro da add node: %s", line);
    node->line = line;
    node->next = NULL;
    if (!data->head)
    {
        data->head = node;
        return;
    }
    current = data->head;
    while (current->next)
        current = current->next;
    current->next = node;
}

