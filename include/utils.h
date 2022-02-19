/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:32:26 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/02/19 12:43:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_matrix
{
	size_t	rows;
	size_t	columns;
	void	**values;
}	t_matrix;

t_matrix	*create_matrix(size_t rows, size_t columns, size_t type_size);
void		destroy_matrix(t_matrix *matrix);

#endif
