#include "so_long.h"

t_matrix	*create_map_description(char *md_file)
{
	int	fd;
	char	*line;
	size_t	rows;
	size_t	columns;

	fd = open(md_file, O_RDWR);
	line = get_next_line(fd);
	rows = 0;
	columns = ft_strlen(line) - 1;
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}	
	close(fd);
	return (create_matrix(rows, columns));
}
