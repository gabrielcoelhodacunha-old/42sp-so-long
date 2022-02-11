#include "so_long.h"

int	handle_keyboard(int key_code, void *game)
{
	ft_printf("Key %i was pressed\n", key_code);
	if (key_code == 0xff1b)
		handle_close(((t_game *) game)->mlx);
	return (0);
}
