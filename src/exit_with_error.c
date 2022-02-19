/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_with_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:32:19 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/02/19 12:32:19 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	build_error(char **error);

void	exit_with_error(t_game *game)
{
	build_error(&game->error);
	perror(game->error);
	destroy_game(game);
	exit(errno);
}

static void	build_error(char **error)
{
	char	*auxiliary;

	auxiliary = ft_strjoin("Error\n\t", *error);
	free(*error);
	*error = ft_strjoin(auxiliary, " ");
	free(auxiliary);
}
