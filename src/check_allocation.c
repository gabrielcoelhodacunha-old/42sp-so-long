#include "so_long.h"

void	check_allocation(t_game *game, void *value, char *name)
{
	if (value)
		return ;
	errno = ENOMEM;
	game->error = ft_strjoin(name, " allocation not possible");
	exit_with_error(game);
}
