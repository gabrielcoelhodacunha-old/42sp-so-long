#include "so_long.h"

void	exit_with_error(t_error *error)
{
	char	*auxiliary;
	char	*full_message;

	auxiliary = ft_strjoin("Error\n\t", error->message);
	full_message = ft_strjoin(auxiliary, " ");
	perror(full_message);
	destroy_matrix(error->map_description);
	free(error->message);
	free(auxiliary);
	free(full_message);
	exit(errno);
}
