#include "so_long.h"

static void	build_error_message(t_error *error);
static void	show_error_message(t_error *error);
static void	clear_error_memory(t_error *error);

void	exit_with_error(t_error *error)
{
	build_error_message(error);
	show_error_message(error);
	clear_error_memory(error);
	exit(errno);
}

static void	clear_error_memory(t_error *error)
{
	destroy_matrix(error->matrix);
	free(error->message);
}

static void	show_error_message(t_error *error)
{
	perror(error->message);
}

static void	build_error_message(t_error *error)
{
	char	*auxiliary;

	auxiliary = ft_strjoin("Error\n\t", error->message);
	free(error->message);
	error->message = ft_strjoin(auxiliary, " ");
	free(auxiliary);
}
