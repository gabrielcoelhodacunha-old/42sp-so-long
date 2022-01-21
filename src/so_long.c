#include "so_long.h"

void	so_long(char *map_file)
{
	char	*line;
	int	fd;

	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
