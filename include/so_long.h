#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "constants.h"
# include "typedefs.h"

void	so_long(char *map_file);

t_imap	create_imap(char *first_line); 
t_imap	read_map_file(char *map_file);
void	destroy_imap(t_imap *m);

void	handle_error(t_error *e);
void	handle_map_file(int fd, char *map_file);
void	handle_line(char *line, t_imap *m);

#endif
