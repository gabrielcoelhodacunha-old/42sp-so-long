#include "so_long.h"

void	fill_map_description(t_matrix *md, char *md_file)
{
	int	fd;
	char	*line;
	size_t	row;

	fd = open(md_file, O_RDWR);
	line = get_next_line(fd);
	row = -1;
	while (line)
	{
		md->values[++row] = line;
		line = get_next_line(fd);
	}
	row = -1;
	while (++row < md->rows)
		printf("%s", md->values[row]);
	close(fd);
}
