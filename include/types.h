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
	void	*empty[EMPTY_FRAMES];
	void	*wall[WALL_FRAMES];
	void	*collectible[COLLECTIBLE_FRAMES];
	void	*exit[EXIT_FRAMES];
	void	*player[PLAYER_FRAMES];
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
	time_t	initial_time;
	char	*error;
}	t_game;

#endif
