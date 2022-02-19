/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:32:19 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/02/19 13:20:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_mlx(t_game *game)
{
	if (game->mlx)
		return ;
	errno = EIO;
	game->error = ft_strdup("MiniLibX could not establish \
			connection between so_long and the display");
	exit_with_error(game);
}
