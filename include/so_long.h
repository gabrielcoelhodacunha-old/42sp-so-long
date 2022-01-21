#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "constants.h"

void	so_long(char *map_file);
char	**read_map_file(char *map_file);

#endif
