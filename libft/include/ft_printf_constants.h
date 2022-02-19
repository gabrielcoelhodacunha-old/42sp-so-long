/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_constants.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcoelho- <gcoelho-@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:48:08 by gcoelho-          #+#    #+#             */
/*   Updated: 2022/02/19 12:32:24 by gcoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_CONSTANTS_H
# define FT_PRINTF_CONSTANTS_H
# define FLAGS "-.# +"
# define NUMBER_OF_FLAGS 8

enum	e_ft_printf_flags
{
	NEGATIVE_WIDTH,
	PRECISION,
	ALTERNATE_FORM,
	BLANK,
	SIGNED,
	ZERO_PADDING,
	FIELD_WIDTH,
	PRECISION_WIDTH
};

#endif
