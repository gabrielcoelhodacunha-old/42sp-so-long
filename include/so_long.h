/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:32:26 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/02/19 12:42:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "mlx.h"
# include "so_long_bonus.h"
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "constants.h"
# include "types.h"
# include "utils.h"

void		so_long(t_game *game, char *map_file);
void		configure_map(t_game *game, char *map_file);
void		configure_collectibles(t_game *game);
void		configure_player(t_game *game);
void		configure_mlx(t_game *game);
void		configure_images(t_game *game);
int			render_game(t_game *game);
void		finish_game(t_game *game);

t_game		*create_game(void);
t_matrix	*create_map(char *file);

void		fill_map(t_matrix *map, char *file);

int			handle_keyboard(int key_code, t_game *game);
int			handle_movement(t_game *game, int key_code);
int			handle_close(void *mlx);

void		check_allocation(t_game *game, void *value, char *name);
void		check_args(t_game *game, int argc, char **argv);
void		check_map_file(t_game *game, char *file);
void		check_map(t_game *game);
void		check_mlx(t_game *game);
void		check_window(t_game *game);
void		check_images(t_game *game);

void		destroy_game(t_game *game);

void		exit_with_error(t_game *game);

#endif
