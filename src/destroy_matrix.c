#include "so_long.h"

void	destroy_matrix(t_matrix *matrix)
{
	size_t	row;

	if (!matrix || !matrix->values)
		return ;
	row = -1;
	while (++row < matrix->rows)
		free(matrix->values[row]);
	free(matrix->values);
	matrix->values = NULL;
	matrix->rows = 0;
	matrix->columns = 0;
}
