#include "so_long.h"

int	handle_mouse(int button, int x, int y, void *mlx)
{
	(void) mlx;
	ft_printf("Pressed button %i at (%i, %i)\n", button, x, y);
	return (0);
}
