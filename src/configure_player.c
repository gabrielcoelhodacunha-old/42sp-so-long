/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:32:19 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/02/19 13:26:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	configure_player(t_game *game)
{
	t_matrix	*m;
	size_t		row;
	size_t		column;
	char		*tile;

	m = game->map;
	row = -1;
	while (++row < m->rows)
	{
		column = -1;
		while (++column < m->columns)
		{
			tile = &((char *) m->values[row])[column];
			if (*tile == PLAYER && !game->player.row)
			{
				game->player.row = row;
				game->player.column = column;
			}
			else if (*tile == PLAYER && game->player.row)
				*tile = EMPTY;
		}
	}
}
