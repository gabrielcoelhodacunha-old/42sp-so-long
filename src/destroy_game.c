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
	int	idx;

	idx = -1;
	while (++idx < EMPTY_FRAMES)
		mlx_destroy_image(game->mlx, game->assets.empty[idx]);
	idx = -1;
	while (++idx < WALL_FRAMES)
		mlx_destroy_image(game->mlx, game->assets.wall[idx]);
	idx = -1;
	while (++idx < COLLECTIBLE_FRAMES)
		mlx_destroy_image(game->mlx, game->assets.collectible[idx]);
	idx = -1;
	while (++idx < EXIT_FRAMES)
	{
		mlx_destroy_image(game->mlx, game->assets.exit_closed[idx]);
		mlx_destroy_image(game->mlx, game->assets.exit_open[idx]);
	}
	idx = -1;
	while (++idx < PLAYER_FRAMES)
		mlx_destroy_image(game->mlx, game->assets.player[idx]);
}

static void	destroy_error(char *error)
{
	if (!error)
		return ;
	free(error);
}
