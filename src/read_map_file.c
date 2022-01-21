#include "so_long.h"

char	**read_map_file(char *map_file)
{
	char	**map;
	char	*line;
	int	fd;

	map = malloc(sizeof(char *));
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		map[0] = line;
		free(line);
		line = get_next_line(fd);
	}
	free(map);
	close(fd);
	return (map);
}
