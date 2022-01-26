#include "so_long.h"

void	print_line(void *line);

void	so_long(char *map_file)
{
	t_imap	imap;

	imap = read_map_file(map_file);
	ft_lstiter(imap.values, print_line);
	destroy_imap(&imap);
}

void	print_line(void *line)
{
	printf("%s", (char *) line);
}
