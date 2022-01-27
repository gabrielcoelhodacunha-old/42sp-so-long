#include "so_long.h"

static void	exit_with_allocation_error(t_matrix *matrix, char *value_name);
static void	check_matrix_allocation(t_matrix *matrix);
static void	check_matrix_values_allocation(t_matrix *matrix);

t_matrix	*create_matrix(size_t rows, size_t columns)
{
	t_matrix	*matrix;

	matrix = malloc(sizeof(t_matrix));
	check_matrix_allocation(matrix);
	matrix->rows = rows;
	matrix->columns = columns;
	matrix->values = malloc(sizeof(char *) * rows);
	check_matrix_values_allocation(matrix);
	return (matrix);
}

static void	check_matrix_values_allocation(t_matrix *matrix)
{
	if (matrix->values)
		return ;
	exit_with_allocation_error(matrix, "matrix.values");
}

static void	check_matrix_allocation(t_matrix *matrix)
{
	if (matrix)
		return ;
	exit_with_allocation_error(matrix, "matrix");
}

static void	exit_with_allocation_error(t_matrix *matrix, char *value_name)
{
	t_error	error;

	errno = ENOMEM;
	error.message = ft_strjoin(value_name, " allocation not possible");
	error.matrix = matrix;
	exit_with_error(&error);
}
