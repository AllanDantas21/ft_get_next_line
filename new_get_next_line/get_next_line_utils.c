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

void copy_lines(t_list *node, char *dest, int start_from_newline)
{
    int i = 0;
    int j = 0;
    int found_newline = 0;

    while (node)
    {
        j = 0;
        while (node->line[j])
        {
            if (start_from_newline && found_newline)
                dest[i++] = node->line[j];
            else if (!start_from_newline)
                dest[i++] = node->line[j];
            if (node->line[j] == '\n')
                found_newline = 1;
            j++;
        }
        node = node->next;
    }
    dest[i] = '\0';
}

void extract_ret_line(t_data *data)
{
    t_list *node;
    char *line;
    int len;
    int i;

    if (!data->head)
        return;
    node = data->head;
    len = 0;
    while (node)
    {
        i = 0;
        while (node->line[i])
        {
            len++;
            if (node->line[i] == '\n')
                break;
            i++;
        }
        node = node->next;
    }
    line = malloc(len + 2);
    if (!line)
        return;
    copy_lines(data->head, line, 0);
    data->ret_line = line;
}

char *extract_backup(t_data *data)
{
    t_list *node;
    char *backup;
    int len;
    int i;
    int found_newline;

    node = data->head;
    len = 0;
    found_newline = 0;
    while (node)
    {
        i = 0;
        while (node->line[i])
        {
            if (found_newline)
                len++;
            if (node->line[i] == '\n')
                found_newline = 1;
            i++;
        }
        node = node->next;
    }
    backup = malloc(len + 2);
    if (!backup)
        return NULL;
    copy_lines(data->head, backup, 1);
    return backup;
}

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