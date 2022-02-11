#include "so_long.h"

void	check_window(t_game *game)
{
	if (game->window.ptr)
		return ;
	errno = EIO;
	game->error = ft_strdup("Could not create mlx window");
	exit_with_error(game);
}
