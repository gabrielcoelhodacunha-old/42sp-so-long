/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_allocation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:32:20 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/02/19 12:32:20 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_allocation(t_game *game, void *value, char *name)
{
	if (value)
		return ;
	errno = ENOMEM;
	game->error = ft_strjoin(name, " allocation not possible");
	exit_with_error(game);
}
