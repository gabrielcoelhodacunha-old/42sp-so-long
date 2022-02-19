/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:32:18 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/02/19 13:32:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	finish_game(t_game *game)
{
	char	*text;
	size_t	width;
	size_t	height;
	int		color;

	text = "Congratulations!";
	width = game->window.width / 2 - ft_strlen(text) * 3;
	height = PIXELS_PER_IMAGE - 6;
	color = 0xffffff;
	mlx_string_put(game->mlx, game->window.ptr,
		width, height, color, text);
}
