#ifndef TYPES_H
# define TYPES_H
# include "utils.h"

typedef struct	s_pwh
{
	void	*ptr;
	int	width;
	int	height;
}	t_pwh;

typedef struct	s_assets
{
	t_pwh	empty;
	t_pwh	wall;
	t_pwh	collectible;
	t_pwh	exit;
	t_pwh	player;
}	t_assets;

typedef struct	s_player
{
	int	row;
	int	column;
	int	moves;
}	t_player;

typedef struct	s_game
{
	t_matrix	*map;
	int	collectibles;
	void	*mlx;
	t_pwh	window;
	t_assets	assets;
	t_player	player;
	char	*error;
}	t_game;

#endif
