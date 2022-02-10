#include "so_long.h"

static int	ends_with_dot_ber(char *file);

static void	check_args(t_game *game, int argc, char **argv)
{
	int	is_ber;

	if (argc == 2)
		is_ber = ends_with_dot_ber(argv[1]);
	if (argc == 2 && is_ber)
		return ;
	if (argc < 2)
		game->error = ft_strdup("One argument is required");
	else if (argc > 2)
		game->error = ft_strdup("Only one argument is required");
	else if (!is_ber)
		game->error = ft_strjoin(argv[1], " does not end with .ber");
	errno = EINVAL;
	exit_with_error(game);
}

static int	ends_with_dot_ber(char *file)
{
	return (!ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4));
}
