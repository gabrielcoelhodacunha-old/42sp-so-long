#include "so_long.h"

void	destroy_matrix(t_matrix *matrix)
{
	size_t	row;

	if (!matrix)
		return ;
	if (!matrix->values)
	{
		free(matrix);
		matrix = NULL;
		return ;
	}
	row = -1;
	while (++row < matrix->rows)
		free(matrix->values[row]);
	free(matrix->values);
	free(matrix);
	matrix = NULL;
}
