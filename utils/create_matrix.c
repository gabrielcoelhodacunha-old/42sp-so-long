#include "so_long.h"

t_matrix	*create_matrix(size_t rows, size_t columns, size_t type_size)
{
	t_matrix	*matrix;

	matrix = malloc(sizeof(matrix));
	if (!matrix)
		return (NULL);
	matrix->rows = rows;
	matrix->columns = columns;
	matrix->values = malloc(type_size * rows);
	if (!matrix->values)
		return (NULL);
	return (matrix);
}
