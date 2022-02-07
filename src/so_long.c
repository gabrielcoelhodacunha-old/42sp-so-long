#include "so_long.h"

void	so_long(void *mlx, t_matrix *map_description)
{
	void	*window;
	t_screen	screen;

	(void) map_description;
	mlx_get_screen_size(mlx, &screen.x, &screen.y);
	window = mlx_new_window(mlx, screen.x / 2, screen.y / 2, "so_long");
	mlx_loop(mlx);
	mlx_destroy_window(mlx, window);
}
