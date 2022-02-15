#include "so_long.h"

void	so_long(t_game *game, char *map_file)
{
	configure_map(game, map_file);
	configure_collectibles(game);
	configure_player(game);
	configure_mlx(game);
}
