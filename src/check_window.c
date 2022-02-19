/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:32:18 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/02/19 12:32:18 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_window(t_game *game)
{
	if (game->window.ptr)
		return ;
	errno = EIO;
	game->error = ft_strdup("Could not create mlx window");
	exit_with_error(game);
}
