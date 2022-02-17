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
	game->initial_time = time(NULL);
	game->error =  NULL;
	return (game);
}
