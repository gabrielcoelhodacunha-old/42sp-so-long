#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("A .ber file must be passed as argument!!\n");
		return (1);
	}
	so_long(argv[1]);
	return (0);
}
