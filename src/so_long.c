#include "so_long.h"

static void	check_argc(int argc);
static void	so_long(char *map_description_file);

int	main(int argc, char **argv)
{
	check_argc(argc);
	so_long(argv[1]);
	exit(EXIT_SUCCESS);
}

static void	so_long(char *map_description_file)
{
	//t_matrix	map_description;

	printf("Map description file : %s\n", map_description_file);
	//map_description = create_map_description(map_description_file);
	//destroy_matrix(&map_description);
}

static void	check_argc(int argc)
{
	t_error	error;

	if (argc == 2)
		return ;
	else if (argc < 2)
		error.message = ft_strdup("One argument is required");
	else if (argc > 2)
		error.message = ft_strdup("Only one argument is required");
	errno = EINVAL;
	error.map_description = NULL;
	exit_with_error(&error);
}
