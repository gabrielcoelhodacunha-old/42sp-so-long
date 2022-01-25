#include "so_long.h"

static void	handle_map_file(int fd, char *map_file);
static void	handle_line(char *line, int columns);
static void	print_line(void *line);

t_imap	read_map_file(char *map_file)
{
	t_imap	map;
	char	*line;
	int	fd;

	fd = open(map_file, O_RDWR);
	handle_map_file(fd, map_file);
	line = get_next_line(fd);
	map = create_imap(line);
	while (line)
	{
		handle_line(line, map.columns);
		map.rows++;
		ft_lstadd_back(&(map.values), ft_lstnew(line));
		line = get_next_line(fd);
	}
	ft_lstiter(map.values, print_line);
	ft_lstclear(&(map.values), free);
	close(fd);
	return (map);
}

static int	has_ber_extension(char *file)
{
	return (!ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4));
}

static void	handle_map_file(int fd, char *map_file)
{
	char	*message;
	int	is_ber;

	is_ber = has_ber_extension(map_file);
	if (fd != -1 && is_ber)
		return ;
	else if (fd == -1)
		message = ft_strjoin("Unable to open ", map_file);
	else if (!is_ber)
	{
		message = ft_strjoin(map_file, " is not of type .ber");
		errno = EINVAL;
	}
	handle_error(errno, &message);
}

static void	print_line(void *line)
{
	printf("%s", (char *) line);
}

static void	handle_line(char *line, int columns, int rows)
{
	size_t	line_len;
	char	*message;

	line_len = ft_strlen(line) - 1;
	if (line_len == columns)
		return ;
	message = ft_strjoin("Invalid number of characters in row ", "");
	handle_error(EINVAL, &message);
}
