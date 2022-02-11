#include "so_long.h"

static void	check_permissions(t_game *game, char *file);
static void	check_content(t_game *game, char *file);

void	check_map_file(t_game *game, char *file)
{
	check_permissions(game, file);
	check_content(game, file);
}

static void	check_permissions(t_game *game, char *file)
{
	int	fd;

	fd = open(file, O_RDWR);
	if (fd != -1)
	{
		close(fd);
		return ;
	}
	game->error = ft_strdup(file);
	exit_with_error(game);
}

static void	check_line(t_game *game, char *line, size_t *format);

static void	check_content(t_game *game, char *file)
{
	int	fd;
	char	*line;
	size_t	format[2];

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	format[0] = 0;
	if (line)
		format[1] = ft_strlen(line) - 1;
	while (line)
	{
		format[0]++;
		check_line(game, line, format);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (format[0])
		return ;
	errno = EINVAL;
	game->error = ft_strjoin(file, " is empty");
	exit_with_error(game);
}

static void	check_line(t_game *game, char *line, size_t *format)
{
	size_t	line_len;
	size_t	idx;
	char	*is_valid;
	char	*row_str;

	line_len = ft_strlen(line) - 1;
	is_valid = line;
	idx = -1;
	while (++idx < line_len && line[idx] && is_valid)
		is_valid = ft_strchr(MAP_COMPONENTS, line[idx]);
	if (line_len == format[1] && is_valid)
		return ;
	row_str = ft_itoa(format[0]);
	if (line_len != format[1])
		game->error = ft_strjoin("Map description file has different number of characters on line ", row_str);
	else if (!is_valid)
		game->error = ft_strjoin("Map description file has invalid characters on line ", row_str);
	errno = EINVAL;
	free(line);
	free(row_str);
	exit_with_error(game);
}
