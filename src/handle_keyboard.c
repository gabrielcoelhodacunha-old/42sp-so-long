#include "so_long.h"

int	handle_keyboard(int key_code, t_game *game)
{
	if (key_code == XK_ESCAPE)
		handle_close(game->mlx);
	else if (key_code == XK_W 
			|| key_code == XK_S
			|| key_code == XK_A
			|| key_code == XK_D)
		handle_movement(game, key_code);
	return (0);
}
