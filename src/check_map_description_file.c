#include "so_long.h"

void	check_map_description_file(char *md_file);
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

static void	check_content(char *md_file)
{
	char	*line;

	line = get_next_line(fd);
	md_format[0] = 0;
	md_format[1] = ft_strlen(line) - 1;
	while (line)
	{
		md_format[0]++;
		check_line_len(line, md_format);
		free(line);
		line = get_next_line(fd);
	}
	check_map_description_format(md_format);
}

static void	check_map_description_format(size_t *md_format)
{
	t_error error;

	if (md_format[0] && md_format[1])
		return ;
	errno = EINVAL;
	error.message = ft_strdup("Map description file is empty");
	error.matrix = NULL;
	exit_with_error(&error);
}

static void	check_line_len(char *line, size_t *md_format)
{
	t_error	error;
	size_t	line_len;
	char	*rows_str;

	line_len = ft_strlen(line) - 1;
	if (line_len == md_format[1])
		return ;
	rows_str = ft_itoa(md_format[0]);
	errno = EINVAL;
	error.message = ft_strjoin("Map description file has line ", rows_str);
	error.matrix = NULL;
	free(line);
	free(rows_str);
	exit_with_error(&error);
}
