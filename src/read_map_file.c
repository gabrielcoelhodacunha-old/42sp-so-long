#include "so_long.h"

t_imap	read_map_file(char *map_file)
{
	t_imap	map;
	char	*line;
	int	fd;
	size_t	rows;
	size_t	columns;

	fd = open(map_file, O_RDWR);
	handle_map_file(fd, map_file);
	rows = 0;
	line = get_next_line(fd);
	columns = ft_strlen(line) - 1;
	while (line)
	{
		rows++;
		handle_line(line, columns);
		line = get_next_line(fd);
	}
	close(fd);
	map = create_imap(rows, columns);
	fd = open(map_file, O_RDWR);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map = create_imap(line);
	return (map);
}
