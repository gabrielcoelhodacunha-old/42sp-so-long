#include "so_long.h"

static int	has_ber_extension(char *file);

void	handle_map_file(int fd, char *map_file)
{
	t_error	e;
	int	is_ber;

	is_ber = has_ber_extension(map_file);
	if (fd != -1 && is_ber)
		return ;
	else if (fd == -1)
		e.message = ft_strjoin("Unable to open ", map_file);
	else if (!is_ber)
	{
		e.message = ft_strjoin(map_file, " is not of type .ber");
		errno = EINVAL;
	}
	e.imap = NULL;
	handle_error(&e);
}

static int	has_ber_extension(char *file)
{
	return (!ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4));
}
