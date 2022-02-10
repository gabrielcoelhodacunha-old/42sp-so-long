#ifndef TYPES_H
# define TYPES_H

typedef struct	s_matrix
{
	size_t	rows;
	size_t	columns;
	char	**values;
}	t_matrix;

typedef struct	s_coordinate
{
	int	x;
	int	y;
}	t_coordinate;

typedef struct	s_error
{
	char	*message;
	t_matrix	*matrix;
}	t_error;

#endif
