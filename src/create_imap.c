#include "so_long.h"

t_imap	create_imap(char *first_line)
{
	t_imap	map;

	map.values = NULL;
	map.rows = 0;
	map.columns = ft_strlen(first_line) - 1;
	return (map);
}
