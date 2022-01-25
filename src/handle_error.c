#include "so_long.h"

void	handle_error(int num, char **message)
{
	char	*full_message;

	full_message = ft_strjoin("Error\n\t", *message);
	errno = num;
	perror(full_message);
	free(full_message);
	free(*message);
	exit(errno);
}
