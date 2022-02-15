#include "so_long.h"

void	configure_collectibles(t_game *game)
{
	size_t	r;
	size_t	c;
	char	*row;

	r = -1;
	while (++r < game->map->rows)
	{
		row = (char *) game->map->values[r];
		c = -1;
		while (++c < game->map->columns)
			if (row[c] == COLLECTIBLE)
				game->collectibles++;
	}
}
