#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	ft_printf("t_game = %u\n", sizeof(t_game));
	game = create_game();
	check_args(game, argc, argv);
	so_long(game, argv[1]);
	destroy_game(game);
	exit(EXIT_SUCCESS);
}
