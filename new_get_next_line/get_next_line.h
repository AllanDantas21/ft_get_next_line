

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
    char          *data;
    struct s_list *next;
}   t_list;

size_t  ft_strlen(const char *s);
char    *get_next_line(int fd);
char    *ft_strjoin(const char *s1, const char *s2);
char    *ft_strchr(const char *s, int c);
char    *ft_strdup(const char *s);
char    *ft_strndup(const char *s, size_t n);

#endif
