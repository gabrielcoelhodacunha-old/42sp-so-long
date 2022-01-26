#include "so_long.h"

t_imap	read_map_file(char *map_file)
{
	t_imap	map;
	char	*line;
	int	fd;

	fd = open(map_file, O_RDWR);
	handle_map_file(fd, map_file);
	line = get_next_line(fd);
	map = create_imap(line);
	while (line)
	{
		map.rows++;
		ft_lstadd_back(&(map.values), ft_lstnew(line));
		handle_line(line, &map);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
