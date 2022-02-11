#include "so_long.h"

void	so_long(t_game *game, char *map_file)
{
	size_t	x, y;

	check_map_file(game, map_file);
	game->map = create_map(map_file);
	check_allocation(game, game->map, "game.map");
	fill_map(game->map, map_file);
	check_map(game);

	game->mlx = mlx_init();
	check_mlx(game);


	//mlx_get_screen_size(game->mlx, &x, &y);
	x = game->map->columns * 16;
	y = game->map->rows * 16;
	game->window = mlx_new_window(game->mlx, x, y, "so_long");
	//mlx_key_hook(game->window, handle_keyboard, game->mlx);
	mlx_mouse_hook(game->window, handle_mouse, 0);
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, handle_close, game->mlx);

	mlx_loop(game->mlx);
}
