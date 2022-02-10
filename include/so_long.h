#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <X11/X.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "constants.h"
# include "types.h"
# include "utils.h"

void	so_long(t_game *game, char *map_file);

t_game	*create_game(void);
t_matrix	*create_map(char *file);

void	fill_map(t_matrix *map, char *file);

int	handle_mouse(int button, int x, int y, void *param);
int	handle_close(void *mlx);

void	check_allocation(t_game *game, void *value, char *name);
void	check_args(t_game *game, int argc, char **argv);
void	check_map_file(t_game *game, char *file);
void	check_map(t_game *game);
void	check_mlx(t_game *game);

void	destroy_game(t_game *game);

void	exit_with_error(t_game *game);

#endif
