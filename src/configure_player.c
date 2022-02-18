#include "so_long.h"

void	configure_player(t_game *game)
{
	t_matrix	*m;
	size_t	row;
	size_t	column;
	char	*tile;

	m = game->map;
	row = -1;
	while (++row < m->rows)
	{
		column = -1;
		while (++column < m->columns)
		{
			tile = &((char *) m->values[row])[column];
			if (*tile == PLAYER && !game->player.row)
			{
				game->player.row = row;
				game->player.column = column;
			}
			else if (*tile == PLAYER && game->player.row)
				*tile = EMPTY;
		}
	}
}
