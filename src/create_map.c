/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:32:18 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/02/19 13:27:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_matrix	*create_map(char *file)
{
	int		fd;
	char	*line;
	size_t	rows;
	size_t	columns;

	fd = open(file, O_RDWR);
	line = get_next_line(fd);
	rows = 0;
	columns = ft_strlen(line) - 1;
	while (line)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (create_matrix(rows, columns, sizeof(char *)));
}
