/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:32:26 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/02/19 12:32:26 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H
# define PIXELS_PER_IMAGE 32
# define MAP_COMPONENTS "01CEP"
# define XPM_EMPTY "images/empty_"
# define XPM_WALL "images/wall_"
# define XPM_COLLECTIBLE "images/collectible_"
# define XPM_EXIT_CLOSED "images/exit_closed_"
# define XPM_EXIT_OPEN "images/exit_open_"
# define XPM_PLAYER "images/player_"
# define EMPTY_FRAMES 1
# define WALL_FRAMES 4
# define COLLECTIBLE_FRAMES 5
# define EXIT_FRAMES 4
# define PLAYER_FRAMES 12

enum	e_components
{
	EMPTY = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	PLAYER = 'P'
};

enum	e_x11_events
{
	KeyPress = 2,
	DestroyNotify = 17
};

enum	e_x11_masks
{
	KeyPressMask = (1L << 0),
	StructureNotifyMask = (1L << 17)
};

enum	e_x11_keys
{
	XK_ESCAPE = 65307,
	XK_W = 119,
	XK_A = 97,
	XK_S = 115,
	XK_D = 100
};

#endif
