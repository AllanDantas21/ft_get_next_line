#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		fd;
	const	char *file_name = "teste.txt";

	fd = open(file_name, O_RDONLY);

	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	close(fd);
	return 0;
}
