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

  node = malloc(sizeof(t_list));
  node->line = line;
  if (!node)
    return ;
  if (!data->head)
  {
    data->head = node;
    return ;
  }
  while (data->head->next)
    data->head = data->head->next;
  data->head = node;
}
