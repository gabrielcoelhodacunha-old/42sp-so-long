#include "so_long.h"

t_matrix	*create_map_description(char *map_description_file)
{
	t_matrix	*map_description;
	int	file_descriptor;

	file_descriptor = open(map_description_file, O_RDWR);
	get_map_description_format(file_descriptor, map_description);
	return (map_description);
}

static void	get_map_description_format(int file_descriptor, t_matrix *map_description)
{
	char	*line;
	size_t	rows;
	size_t	columns;

	check_map_description_file(file_descriptor);
	line = get_next_line(file_descriptor);
	rows = 0;
	columns = ft_strlen(line) - 1;
	while (line)
	{
		check_line_len(line, columns, ++rows);
		free(line);
		line = get_next_line(file_descriptor);
	}
	close(file_descriptor);
	map_description = create_matrix(rows, columns);
}

static void	check_line_len(char *line, size_t columns, size_t rows)
{
	t_erro	error;
	size_t	line_len;
	char	*rows_str;
	char	*message;

	line_len = ft_strlen(line) - 1;
	if (line_len == columns)
		return ;
	rows_str = ft_itoa(rows);
	message = ft_strjoin("Invalid number of characters in line ", rows_str);
	set_error(&error, EINVAL, message, NULL);
	free(rows_str);
	exit_with_error(&error);
}
