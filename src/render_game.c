#include "so_long.h"

static void	show_moves(t_game *game);
static void	render_image(t_game *game, size_t row, size_t column, time_t ssi);

int	render_game(t_game *game)
{
	time_t	seconds_since_initialization;
	size_t	row;
	size_t	column;

	show_moves(game);
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

static void	show_moves(t_game *game)
{
	void	*image;
	char	*moves;
	char	*text;

	image = mlx_new_image(game->mlx, game->window.width, 
			PIXELS_PER_IMAGE / 2);
	mlx_put_image_to_window(game->mlx, game->window.ptr, image, 0, 0);
	moves = ft_itoa(game->player.moves);
	text = ft_strjoin("Moves : ", moves);
	mlx_string_put(game->mlx, game->window.ptr, 
			game->window.width / 2 - ft_strlen(text) * 3,
			PIXELS_PER_IMAGE / 2 - 6,
			0xffffff, text);
	mlx_destroy_image(game->mlx, image);
	free(moves);
	free(text);
}

static void	render_image(t_game *game, size_t row, size_t column, time_t ssi)
{
	char	type;
	void	*image;

	type = ((char *) game->map->values[row])[column];
	if (type == EMPTY)
		image = game->images.empty[ssi % EMPTY_FRAMES];
	else if (type == WALL)
		image = game->images.wall[ssi % WALL_FRAMES];
	else if (type == COLLECTIBLE)
		image = game->images.collectible[ssi % COLLECTIBLE_FRAMES];
	else if (type == EXIT && game->collectibles)
		image = game->images.exit_closed[ssi % EXIT_FRAMES];
	else if (type == EXIT && !game->collectibles)
		image = game->images.exit_open[ssi % EXIT_FRAMES];
	else if (type == PLAYER)
		image = game->images.player[ssi % PLAYER_FRAMES];
	mlx_put_image_to_window(game->mlx, game->window.ptr, image, 
			PIXELS_PER_IMAGE * column, PIXELS_PER_IMAGE * (row + 1));
}
