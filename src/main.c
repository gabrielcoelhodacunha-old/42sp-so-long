#include "so_long.h"

static void	check_args(int argc, char **argv);

int	main(int argc, char **argv)
{
	char	*map_description_file;
	t_matrix	*map_description;
	void	*mlx;

	check_args(argc, argv);
	map_description_file = argv[1];
	check_map_description_file(map_description_file);
	map_description = create_map_description(map_description_file);
	fill_map_description(map_description, map_description_file);
	check_map_description(map_description);
	mlx = mlx_init();
	check_mlx(mlx, map_description);
	so_long(mlx, map_description);
	destroy_matrix(map_description);
	mlx_destroy_display(mlx);
	free(mlx);
	exit(EXIT_SUCCESS);
}

static int	ends_with_dot_ber(char *file);

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

static int	ends_with_dot_ber(char *file)
{
	return (!ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4));
}
