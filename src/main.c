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

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("A .ber file must be passed as argument!\n");
		return (1);
	}
	so_long(argv[1]);
	return (0);
}
