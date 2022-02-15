#include "so_long.h"

void	configure_player(t_game *game)
{
	t_matrix	*m;
	size_t	row;
	char	*p;

	m = game->map;
	row = -1;
	while (++row < m->rows)
	{
		p = ft_strchr(m->values[row], PLAYER);
		if (p)
		{
			game->player.row = row;
			game->player.column = p - (char *) m->values[row];
			break ;
		}
	}
}
