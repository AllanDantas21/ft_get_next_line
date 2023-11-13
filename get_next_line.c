#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd, int buffer_s)
{
	char	buffer[buffer_s];

	read(fd, buffer, buffer_s);
	
	printf("%s", buffer);
	return 0;
}
