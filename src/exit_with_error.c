#include "so_long.h"

static void	build_error(char **error);

void	exit_with_error(t_game *game)
{
	build_error(&game->error);
	perror(game->error);
	destroy_game(game);
	exit(errno);
}

static void	build_error(char **error)
{
	char	*auxiliary;

	auxiliary = ft_strjoin("Error\n\t", *error);
	free(*error);
	*error = ft_strjoin(auxiliary, " ");
	free(auxiliary);
}
