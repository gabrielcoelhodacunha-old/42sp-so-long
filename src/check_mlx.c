#include "so_long.h"

void	check_mlx(t_game *game)
{
	if (game->mlx)
		return ;
	errno = EIO;
	game->error = ft_strdup("MiniLibX could not establish connection between so_long and the display");
	exit_with_error(game);
}
