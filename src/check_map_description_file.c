#include "so_long.h"

static void	check_permissions(char *md_file);
static void	check_content(char *md_file);

void	check_map_description_file(char *md_file)
{
	check_permissions(md_file);
	check_content(md_file);
}

static void	check_permissions(char *md_file)
{
	int	fd;
	t_error error;

	fd = open(md_file, O_RDWR);
	if (fd != -1)
	{
		close(fd);
		return ;
	}
	error.message = ft_strdup(md_file);
	error.matrix = NULL;
	exit_with_error(&error);
}

static void	check_line(char *line, size_t *md_format, t_error *error);

static void	check_content(char *md_file)
{
	t_error error;
	int	fd;
	char	*line;
	size_t	md_format[2];

	fd = open(md_file, O_RDWR);
	line = get_next_line(fd);
	md_format[0] = 0;
	if (line)
		md_format[1] = ft_strlen(line) - 1;
	while (line)
	{
		md_format[0]++;
		check_line(line, md_format, &error);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (md_format[0])
		return ;
	errno = EINVAL;
	error.message = ft_strjoin(md_file, " is empty");
	error.matrix = NULL;
	exit_with_error(&error);
}

static void	check_line(char *line, size_t *md_format, t_error *error)
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
	if (line_len == md_format[1] && is_valid)
		return ;
	row_str = ft_itoa(md_format[0]);
	if (line_len != md_format[1])
		error->message = ft_strjoin("Map description file has different number of characters on line ", row_str);
	else if (!is_valid)
		error->message = ft_strjoin("Map description file has invalid characters on line ", row_str);
	errno = EINVAL;
	error->matrix = NULL;
	free(line);
	free(row_str);
	exit_with_error(error);
}
