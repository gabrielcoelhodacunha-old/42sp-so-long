#include "so_long.h"

static void	set_images(t_game *game, void **component, char *initial_path, int frames);

void	configure_images(t_game *game)
{
	set_images(game, game->images.empty, XPM_EMPTY, EMPTY_FRAMES);
	set_images(game, game->images.wall, XPM_WALL, WALL_FRAMES);
	set_images(game, game->images.collectible, XPM_COLLECTIBLE, COLLECTIBLE_FRAMES);
	set_images(game, game->images.exit_closed, XPM_EXIT_CLOSED, EXIT_FRAMES);
	set_images(game, game->images.exit_open, XPM_EXIT_OPEN, EXIT_FRAMES);
	set_images(game, game->images.player, XPM_PLAYER, PLAYER_FRAMES);
}

static void	set_images(t_game *game, void **images, char *initial_path, int frames)
{
	int	idx;
	int	width;
	int	height;
	char	*file;
	char	*auxiliary;

	idx = -1;
	while (++idx < frames)
	{
		file = ft_itoa(idx);
		auxiliary = ft_strjoin(initial_path, file);
		free(file);
		file = ft_strjoin(auxiliary, ".xpm");
		images[idx] = mlx_xpm_file_to_image(game->mlx, file, &width, &height);
		free(auxiliary);
		free(file);
	}
}
