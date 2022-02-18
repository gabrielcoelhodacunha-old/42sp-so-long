#ifndef CONSTANTS_H
# define CONSTANTS_H
# define DestroyNotify 17
# define StructureNotifyMask (1L << 17)
# define PIXELS_PER_IMAGE 32
# define MAP_COMPONENTS "01CEP"
# define XPM_EMPTY "assets/empty_"
# define XPM_WALL "assets/wall_"
# define XPM_COLLECTIBLE "assets/collectible_"
# define XPM_EXIT_CLOSED "assets/exit_closed_"
# define XPM_EXIT_OPEN "assets/exit_open_"
# define XPM_PLAYER "assets/player_"
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

enum	e_x11_keys
{
	XK_ESCAPE = 65307,
	XK_W = 119,
	XK_A = 97,
	XK_S = 115,
	XK_D = 100
};

#endif
