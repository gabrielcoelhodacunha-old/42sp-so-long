#ifndef TYPES_H
# define TYPES_H

typedef struct	s_matrix
{
	size_t	rows;
	size_t	columns;
	void	**values;
}	t_matrix;

typedef struct	s_game
{
	t_matrix	*map;
	void	*mlx;
	void	*window;
	char	*error;
}	t_game;

#endif
