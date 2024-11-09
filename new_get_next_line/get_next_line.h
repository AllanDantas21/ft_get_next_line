

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_list
{
  char *line;
  struct s_list *next;
} t_list;

typedef struct s_data
{
  int     fd;
  char    *line;
  char    *ret_line;
  t_list  *head;
} t_data;

void extract_ret_line(t_list *list);
void free_all_list(t_data *data);
void add_node_in_list(t_data *data, char *line);

#endif
