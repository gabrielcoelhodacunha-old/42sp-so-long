#include "so_long.h"

static void	handle_argc(int argc);

int	main(int argc, char **argv)
{
	handle_argc(argc);
	so_long(argv[1]);
	return (0);
}

static void	handle_argc(int argc)
{
	t_error	e;

	if (argc == 2)
		return ;
	else if (argc < 2)
		e.message = ft_strjoin("", "One argument is required");
	else if (argc > 2)
		e.message = ft_strjoin("", "Only one argument is required");
	errno = EINVAL;
	e.imap = NULL;
	handle_error(&e);
}
