/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:32:20 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/02/19 13:28:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_mlx(t_game *game);
static void	destroy_images(t_game *game);
static void	destroy_component_images(t_game *game, void**images, int frames);
static void	destroy_error(char *error);

void	destroy_game(t_game *game)
{
	if (!game)
		return ;
	destroy_matrix(game->map);
	destroy_mlx(game);
	destroy_error(game->error);
	free(game);
	game = NULL;
}

static void	destroy_mlx(t_game *game)
{
	if (!game->mlx && !game->window.ptr)
		return ;
	destroy_images(game);
	if (game->window.ptr)
		mlx_destroy_window(game->mlx, game->window.ptr);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

static void	destroy_images(t_game *game)
{
	destroy_component_images(game, game->images.empty,
		EMPTY_FRAMES);
	destroy_component_images(game, game->images.wall,
		WALL_FRAMES);
	destroy_component_images(game, game->images.collectible,
		COLLECTIBLE_FRAMES);
	destroy_component_images(game, game->images.exit_closed,
		EXIT_FRAMES);
	destroy_component_images(game, game->images.exit_open,
		EXIT_FRAMES);
	destroy_component_images(game, game->images.player,
		PLAYER_FRAMES);
}

static void	destroy_component_images(t_game *game, void**images, int frames)
{
	int	idx;

	idx = -1;
	while (++idx < frames)
		if (images[idx])
			mlx_destroy_image(game->mlx, images[idx]);
}

static void	destroy_error(char *error)
{
	if (!error)
		return ;
	free(error);
}
