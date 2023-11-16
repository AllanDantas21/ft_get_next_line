#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		fd;
	const	char *file_name = "teste.txt";
	char	*line;

	fd = open(file_name, O_RDONLY);

	line = get_next_line(fd);
	printf("%s\n", line);
	//line = get_next_line(fd);
	//printf("%s\n", line);
	close(fd);
	return 0;
}
