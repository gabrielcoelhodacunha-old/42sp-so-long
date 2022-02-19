/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:32:19 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/02/19 12:32:19 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_game *game, char *map_file)
{
	configure_map(game, map_file);
	configure_collectibles(game);
	configure_player(game);
	configure_mlx(game);
}
