#include "so_long.h"

t_imap	create_imap(size_t rows, size_t columns)
{
	t_imap	map;
	size_t	row;

	map.rows = rows;
	map.columns = columns;
	map.values = malloc(sizeof(char *) * rows);
	if (!map.values)
		return (NULL);
	row = -1;
	while (++row < rows)
	{
		map.values[row] = malloc(columns);
		if (!map.values[row])
		{
			destroy_imap(&map);
			return (NULL);
		}
	}
	return (map);
}
