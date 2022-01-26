#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "constants.h"
# include "typedefs.h"

t_matrix	create_matrix(size_t rows, size_t columns);
void	destroy_matrix(t_matrix *matrix);

void	exit_with_error(t_error *error);

#endif
