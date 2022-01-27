#include "so_long.h"

static void	check_args(int argc, char **argv);
static void	so_long(char *map_description_file);

int	main(int argc, char **argv)
{
	check_args(argc, argv);
	so_long(argv[1]);
	exit(EXIT_SUCCESS);
}

static void	so_long(char *map_description_file)
{
	t_matrix	*map_description;

	/* Read file */
	//map_description = create_map_description(map_description_file);
	//fill_map_description(map_description, map_description_file);

	/* Check map components*/

	/* Initialize mlx */

	/* Load assets */

	/* Handle events */

	/* Clear memory */
	destroy_matrix(map_description);
}

static int	ends_with_dot_ber(char *file)
{
	return (!ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4));
}

static void	check_args(int argc, char **argv)
{
	t_error	error;
	int	is_ber;

	if (argc == 2)
		is_ber = ends_with_dot_ber(argv[1]);
	if (argc == 2 && is_ber)
		return ;
	else if (argc < 2)
		error.message = ft_strdup("One argument is required");
	else if (argc > 2)
		error.message = ft_strdup("Only one argument is required");
	else if (!is_ber)
		error.message = ft_strjoin(argv[1], " does not end with .ber");
	errno = EINVAL;
	error.matrix = NULL;
	exit_with_error(&error);
}
