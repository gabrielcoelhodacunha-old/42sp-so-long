#include "so_long.h"

int	handle_close(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}
