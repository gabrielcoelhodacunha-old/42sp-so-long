#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef struct	s_matrix
{
	size_t	rows;
	size_t	columns;
	char	**values;
}	t_matrix;

typedef struct	s_error
{
	char	*message;
	t_matrix	*matrix;
}	t_error;

#endif
