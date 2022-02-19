/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:32:20 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/02/19 13:26:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*create_game(void)
{
	t_game	*game;

	game = malloc(sizeof(*game));
	if (!game)
		return (NULL);
	game->collectibles = 0;
	game->error = NULL;
	game->mlx = NULL;
	game->map = NULL;
	game->player.row = 0;
	game->player.column = 0;
	game->player.moves = 0;
	game->window.width = 0;
	game->window.height = 0;
	game->window.ptr = NULL;
	game->initial_time = time(NULL);
	return (game);
}
