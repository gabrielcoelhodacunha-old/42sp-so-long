/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:32:18 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/02/19 12:32:18 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	configure_map(t_game *game, char *map_file)
{
	check_map_file(game, map_file);
	game->map = create_map(map_file);
	check_allocation(game, game->map, "game.map");
	fill_map(game->map, map_file);
	check_map(game);
}
