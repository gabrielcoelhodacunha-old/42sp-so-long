#include "so_long.h"

void	finish_game(t_game *game)
{
	char	*text;

	text = "Congratulations!";
	mlx_string_put(game->mlx, game->window.ptr, 
			game->window.width / 2 - ft_strlen(text) * 3, 
			PIXELS_PER_IMAGE - 6,
			0xffffff, text);
}
