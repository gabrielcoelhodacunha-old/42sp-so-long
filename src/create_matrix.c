#include "so_long.h"

static void	check_matrix_values_allocation(t_matrix *matrix);

t_matrix	create_matrix(size_t rows, size_t columns)
{
	t_matrix	matrix;

	matrix.rows = rows;
	matrix.columns = columns;
	matrix.values = malloc(sizeof(char *) * rows);
	check_matrix_values_allocation(&matrix);
	return (matrix);
}

static void	check_matrix_values_allocation(t_matrix *matrix)
{
	t_error	error;

	if (matrix->values)
		return ;
	errno = ENOMEM;
	error.message = ft_strdup("matrix.values allocation not possible");
	error.map_description = NULL;
	exit_with_error(&error);
}
