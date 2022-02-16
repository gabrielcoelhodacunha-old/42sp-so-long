#include "so_long.h"

t_game	*create_game(void)
{
	t_game	*game;

	game = malloc(sizeof(*game));
	if (!game)
		return (NULL);
	game->collectibles = 0;
	game->map = NULL;
	game->mlx = NULL;
	game->window.ptr = NULL;
	game->assets.wall_frame = 0;
	game->assets.collectible_frame = 0;
	game->assets.exit_frame = 0;
	game->assets.player_frame = 0;
	game->error =  NULL;
	return (game);
}
