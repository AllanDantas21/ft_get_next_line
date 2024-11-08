

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
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
  struct s_list  *next;
} t_data;


#endif
