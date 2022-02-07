#include "so_long.h"

void	so_long(void *mlx, t_matrix *map_description)
{
	t_coordinate	screen;
	void	*window;
	void	*empty;
	t_coordinate	e;

	(void) map_description;
	mlx_get_screen_size(mlx, &screen.x, &screen.y);
	screen.x = map_description->columns * 16;
	screen.y = map_description->rows * 16;
	window = mlx_new_window(mlx, screen.x, screen.y, "so_long");
	//mlx_key_hook(window, handle_keyboard, mlx);
	mlx_mouse_hook(window, handle_mouse, 0);
	mlx_hook(window, DestroyNotify, StructureNotifyMask, handle_close, mlx);

	empty = mlx_xpm_file_to_image(mlx, XPM_EMPTY, &e.x, &e.y);
	(void) empty;

	mlx_loop(mlx);
	mlx_destroy_window(mlx, window);
}
