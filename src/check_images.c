/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:32:18 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/02/19 12:52:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_component_images(t_game *game,
				char *component,
				void **images,
				int frames);

void	check_images(t_game *game)
{
	check_component_images(game, "empty", game->images.empty,
		EMPTY_FRAMES);
	check_component_images(game, "wall", game->images.wall,
		WALL_FRAMES);
	check_component_images(game, "collectible", game->images.collectible,
		COLLECTIBLE_FRAMES);
	check_component_images(game, "exit_closed", game->images.exit_closed,
		EXIT_FRAMES);
	check_component_images(game, "exit_open", game->images.exit_open,
		EXIT_FRAMES);
	check_component_images(game, "player", game->images.player,
		PLAYER_FRAMES);
}

static void	check_component_images(t_game *game,
				char *component,
				void **images,
				int frames)
{
	int	is_valid;
	int	idx;

	is_valid = 1;
	idx = -1;
	while (++idx < frames && is_valid)
		if (!images[idx])
			is_valid = 0;
	if (is_valid)
		return ;
	errno = EINVAL;
	game->error = ft_strjoin("Could not find xpm of component ", component);
	exit_with_error(game);
}
