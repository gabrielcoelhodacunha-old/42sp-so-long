/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:32:19 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/02/19 13:29:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map(t_matrix *map, char *file)
{
	int		fd;
	char	*line;
	size_t	row;

	fd = open(file, O_RDWR);
	line = get_next_line(fd);
	row = -1;
	while (line)
	{
		map->values[++row] = line;
		line = get_next_line(fd);
	}
	close(fd);
}
