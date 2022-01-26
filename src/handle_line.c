#include "so_long.h"

void	handle_line(char *line, t_imap *m)
{
	t_error	e;
	size_t	line_len;
	char 	*str_rows;

	line_len = ft_strlen(line) - 1;
	if (line_len == m->columns)
		return ;
	str_rows = ft_itoa(m->rows);
	errno = EINVAL;
	e.message = ft_strjoin("Invalid number of characters in row ", str_rows);
	e.imap = m;
	free(str_rows);
	handle_error(&e);
}
