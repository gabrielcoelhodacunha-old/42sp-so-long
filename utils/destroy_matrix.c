/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:32:30 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/02/19 12:32:30 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_matrix(t_matrix *matrix)
{
	size_t	row;

	if (!matrix)
		return ;
	if (!matrix->values)
	{
		free(matrix);
		matrix = NULL;
		return ;
	}
	row = -1;
	while (++row < matrix->rows)
		free(matrix->values[row]);
	free(matrix->values);
	free(matrix);
	matrix = NULL;
}
