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

static void	set_images(t_game *game, void **component, char *initial_path, int frames)
{
	int	idx;
	int	width;
	int	height;
	char	*asset;
	char	*auxiliary;

	idx = -1;
	while (++idx < frames)
	{
		asset = ft_itoa(idx);
		auxiliary = ft_strjoin(initial_path, asset);
		free(asset);
		asset = ft_strjoin(auxiliary, ".xpm");
		component[idx] = mlx_xpm_file_to_image(game->mlx, asset, &width, &height);
		free(auxiliary);
		free(asset);
	}
}

static void	configure_images(t_game *game)
{
	set_images(game, game->assets.empty, XPM_EMPTY, EMPTY_FRAMES);
	set_images(game, game->assets.wall, XPM_WALL, WALL_FRAMES);
	set_images(game, game->assets.collectible, XPM_COLLECTIBLE, COLLECTIBLE_FRAMES);
	set_images(game, game->assets.exit_closed, XPM_EXIT_CLOSED, EXIT_FRAMES);
	set_images(game, game->assets.exit_open, XPM_EXIT_OPEN, EXIT_FRAMES);
	set_images(game, game->assets.player, XPM_PLAYER, PLAYER_FRAMES);
}

static void	render_image(t_game *game, size_t row, size_t column, time_t ssi)
{
	char	type;
	void	*image;

	type = ((char *) game->map->values[row])[column];
	if (type == EMPTY)
		image = game->assets.empty[ssi % EMPTY_FRAMES];
	else if (type == WALL)
		image = game->assets.wall[ssi % WALL_FRAMES];
	else if (type == COLLECTIBLE)
		image = game->assets.collectible[ssi % COLLECTIBLE_FRAMES];
	else if (type == EXIT && game->collectibles)
		image = game->assets.exit_closed[ssi % EXIT_FRAMES];
	else if (type == EXIT && !game->collectibles)
		image = game->assets.exit_open[ssi % EXIT_FRAMES];
	else if (type == PLAYER)
		image = game->assets.player[ssi % PLAYER_FRAMES];
	if (!image)
		return ;
	mlx_put_image_to_window(game->mlx, game->window.ptr, image, 
			PIXEL_PER_IMAGE * column, PIXEL_PER_IMAGE * (row + 1));
}

static int	render_game(t_game *game)
{
	time_t	seconds_since_initialization;
	size_t	row;
	size_t	column;

	seconds_since_initialization = time(NULL) - game->initial_time;
	row = -1;
	while (++row < game->map->rows)
	{
		column = -1;
		while (++column < game->map->columns)
			render_image(game, row, column, seconds_since_initialization);
	}
	return (0);
}

static void	configure_events(t_game *game)
{
	mlx_key_hook(game->window.ptr, handle_keyboard, game);
	mlx_hook(game->window.ptr, DestroyNotify, StructureNotifyMask, 
			handle_close, game->mlx);
	mlx_loop_hook(game->mlx, render_game, game);
}
