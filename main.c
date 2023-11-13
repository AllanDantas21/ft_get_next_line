#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int	fd;
	const char *file_name = "teste.txt";

	fd = open(file_name, O_RDONLY);

	get_next_line(fd, 20);
	close(fd);
}
