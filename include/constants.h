#ifndef CONSTANTS_H
# define CONSTANTS_H
# define PIXEL_PER_IMAGE 32
# define MAP_COMPONENTS "01CEP"
# define XPM_EMPTY "assets/empty.xpm"
# define XPM_WALL "assets/wall.xpm"
# define XPM_COLLECTIBLE "assets/collectible.xpm"
# define XPM_EXIT "assets/exit.xpm"
# define XPM_PLAYER "assets/player.xpm"

enum	e_components
{
	EMPTY = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	EXIT = 'E',
	PLAYER = 'P'
};

#endif
