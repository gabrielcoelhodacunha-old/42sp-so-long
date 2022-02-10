#include "so_long.h"

int	handle_mouse(int button, int x, int y, void *param)
{
	(void) param;
	ft_printf("Pressed button %i at (%i, %i)\n", button, x, y);
	return (0);
}
