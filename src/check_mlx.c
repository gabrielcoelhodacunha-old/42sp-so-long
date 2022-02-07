#include "so_long.h"

void	check_mlx(void *mlx, t_matrix *map_description)
{
	t_error	error;

	if (mlx)
		return ;
	errno = EIO;
	error.message = ft_strdup("MiniLibX could not establish connection between so_long and the display");
	error.matrix = map_description;
	exit_with_error(&error);
}
