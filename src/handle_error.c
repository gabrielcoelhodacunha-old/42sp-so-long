#include "so_long.h"

void	handle_error(t_error *e)
{
	char	*full_message;

	full_message = ft_strjoin("Error\n\t", e->message);
	perror(full_message);
	free(full_message);
	free(e->message);
	destroy_imap(e->imap);
	exit(errno);
}
