#include "so_long.h"

void	so_long(char *map_description_file)
{
	t_matrix	*map_description;
	void	*mlx;
	
	
	t_coordinate	screen;
	void	*window;

	check_map_description_file(map_description_file);
	map_description = create_map_description(map_description_file);
	fill_map_description(map_description, map_description_file);
	check_map_description(map_description);


	mlx = mlx_init();
	check_mlx(mlx, map_description);


	mlx_get_screen_size(mlx, &screen.x, &screen.y);
	screen.x = map_description->columns * 16;
	screen.y = map_description->rows * 16;
	window = mlx_new_window(mlx, screen.x, screen.y, "so_long");
	//mlx_key_hook(window, handle_keyboard, mlx);
	mlx_mouse_hook(window, handle_mouse, 0);
	mlx_hook(window, DestroyNotify, StructureNotifyMask, handle_close, mlx);

	mlx_loop(mlx);
	
	destroy_matrix(map_description);
	mlx_destroy_window(mlx, window);
	mlx_destroy_display(mlx);
	free(mlx);
}
