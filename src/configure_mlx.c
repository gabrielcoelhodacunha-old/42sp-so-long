#include "so_long.h"

static void	configure_window(t_game *game);
static void	configure_events(t_game *game);

void	configure_mlx(t_game *game)
{
	game->mlx = mlx_init();
	check_mlx(game);
	configure_window(game);
	check_window(game);
	configure_images(game);
	check_images(game);
	configure_events(game);
	mlx_loop(game->mlx);
}

static void	configure_window(t_game *game)
{
	game->window.width = PIXELS_PER_IMAGE * game->map->columns;
	game->window.height = PIXELS_PER_IMAGE * (game->map->rows + 1);
	game->window.ptr = mlx_new_window(game->mlx, game->window.width, 
			game->window.height, "so_long");
}

static void	configure_events(t_game *game)
{
	mlx_key_hook(game->window.ptr, handle_keyboard, game);
	mlx_hook(game->window.ptr, DestroyNotify, StructureNotifyMask, 
			handle_close, game->mlx);
	mlx_loop_hook(game->mlx, render_game, game);
}
