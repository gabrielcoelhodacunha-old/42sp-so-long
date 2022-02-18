#ifndef TYPES_H
# define TYPES_H
# include "utils.h"

typedef struct	s_window
{
	int	width;
	int	height;
	void	*ptr;
}	t_window;

typedef struct	s_images
{
	void	*empty[EMPTY_FRAMES];
	void	*wall[WALL_FRAMES];
	void	*collectible[COLLECTIBLE_FRAMES];
	void	*exit_closed[EXIT_FRAMES];
	void	*exit_open[EXIT_FRAMES];
	void	*player[PLAYER_FRAMES];
}	t_images;

typedef struct	s_player
{
	int	row;
	int	column;
	int	moves;
}	t_player;

typedef struct	s_game
{
	int	collectibles;
	char	*error;
	void	*mlx;
	time_t	initial_time;
	t_images	images;
	t_matrix	*map;
	t_player	player;
	t_window	window;
}	t_game;

#endif
