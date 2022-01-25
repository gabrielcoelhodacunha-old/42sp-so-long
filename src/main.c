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
	char	*message;

	if (argc == 2)
		return ;
	else if (argc < 2)
		message = ft_strjoin("", "One argument is required");
	else if (argc > 2)
		message = ft_strjoin("", "Only one argument is required");
	handle_error(EINVAL, &message);
}
