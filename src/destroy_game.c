#include "so_long.h"

static void	destroy_mlx(t_game *game);
static void	destroy_error(char *error);

void	destroy_game(t_game *game)
{
	if (!game)
		return ;
	destroy_matrix(game->map);
	destroy_mlx(game);
	destroy_error(game->error);
	free(game);
	game = NULL;
}

static void	destroy_assets(t_game *game);

static void	destroy_mlx(t_game *game)
{
	if (!game->mlx && !game->window.ptr)
		return ;
	destroy_assets(game);
	if (game->window.ptr)
		mlx_destroy_window(game->mlx, game->window.ptr);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

static void	destroy_assets(t_game *game)
{
	mlx_destroy_image(game->mlx, game->assets.empty.ptr);
	mlx_destroy_image(game->mlx, game->assets.wall.ptr);
	mlx_destroy_image(game->mlx, game->assets.collectible.ptr);
	mlx_destroy_image(game->mlx, game->assets.exit.ptr);
	mlx_destroy_image(game->mlx, game->assets.player.ptr);
}

static void	destroy_error(char *error)
{
	if (!error)
		return ;
	free(error);
}
