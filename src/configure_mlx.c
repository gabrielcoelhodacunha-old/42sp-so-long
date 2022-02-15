#include "so_long.h"

static void	configure_window(t_game *game);
static void	configure_images(t_game *game);
static void	configure_events(t_game *game);

void	configure_mlx(t_game *game)
{
	game->mlx = mlx_init();
	check_mlx(game);
	configure_window(game);
	check_window(game);
	configure_images(game);
	//check_images(game);
	configure_events(game);

	mlx_loop(game->mlx);
}

static void	configure_window(t_game *game)
{
	game->window.width = PIXEL_PER_IMAGE * game->map->columns;
	game->window.height = PIXEL_PER_IMAGE * (game->map->rows + 1);
	game->window.ptr = mlx_new_window(game->mlx, game->window.width, 
			game->window.height, "so_long");
}

static void	configure_images(t_game *game)
{
	game->assets.empty.ptr = mlx_xpm_file_to_image(game->mlx, XPM_EMPTY, 
			&game->assets.empty.width, &game->assets.empty.height);
	game->assets.wall.ptr = mlx_xpm_file_to_image(game->mlx, XPM_WALL, 
			&game->assets.wall.width, &game->assets.wall.height);
	game->assets.collectible.ptr = mlx_xpm_file_to_image(game->mlx, XPM_COLLECTIBLE, 
			&game->assets.collectible.width, &game->assets.collectible.height);
	game->assets.exit.ptr = mlx_xpm_file_to_image(game->mlx, XPM_EXIT, 
			&game->assets.exit.width, &game->assets.exit.height);
	game->assets.player.ptr = mlx_xpm_file_to_image(game->mlx, XPM_PLAYER, 
			&game->assets.player.width, &game->assets.player.height);
}

static void	render_image(t_game *game, size_t row, size_t column)
{
	char	type;
	void	*image;

	type = ((char *) game->map->values[row])[column];
	if (type == EMPTY)
		image = game->assets.empty.ptr;
	else if (type == WALL)
		image = game->assets.wall.ptr;
	else if (type == COLLECTIBLE)
		image = game->assets.collectible.ptr;
	else if (type == EXIT)
		image = game->assets.exit.ptr;
	else if (type == PLAYER)
		image = game->assets.player.ptr;
	if (!image)
		return ;
	mlx_put_image_to_window(game->mlx, game->window.ptr, image, 
			PIXEL_PER_IMAGE * column, PIXEL_PER_IMAGE * (row + 1));
}

static int	render_game(t_game *game)
{
	size_t	row;
	size_t	column;

	row = -1;
	while (++row < game->map->rows)
	{
		column = -1;
		while (++column < game->map->columns)
			render_image(game, row, column);
	}
	return (0);
}

static void	configure_events(t_game *game)
{
	mlx_key_hook(game->window.ptr, handle_keyboard, game);
	mlx_mouse_hook(game->window.ptr, handle_mouse, game->mlx);
	mlx_hook(game->window.ptr, DestroyNotify, StructureNotifyMask, 
			handle_close, game->mlx);
	mlx_loop_hook(game->mlx, render_game, game);
}
