#include "so_long.h"

static void	destroy_mlx(t_game *game);
static void	destroy_error(char *error);

void	destroy_game(t_game *game)
{
	destroy_matrix(game->map_description);
	destroy_mlx(game);
	destroy_error(game->error);
	free(game);
}

static void	destroy_mlx(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

static void	destroy_error(char *error)
{
	free(error);
	error = NULL;
}
