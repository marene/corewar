/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcvect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 17:20:20 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/08 17:20:21 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimage.h"

t_cvect	getcvect(t_cpoint p1, t_cpoint p2)
{
	t_point	dif;
	t_cvect	vec;

	dif = setpoint(p2.x - p1.x, p2.y - p1.y);
	if (ABS(dif.x) > ABS(dif.y))
	{
		vec.x = dif.x > 0 ? 1.0 : -1.0;
		vec.y = (double)dif.y / ABS(dif.x);
		vec.iter = ABS(dif.x);
	}
	else
	{
		vec.y = dif.y > 0 ? 1.0 : -1.0;
		vec.x = (double)dif.x / ABS(dif.y);
		vec.iter = ABS(dif.y);
	}
	vec.color.blue = ((double)((int)(C_BLUE(p2.color)
		- C_BLUE(p1.color)))) / ((double)vec.iter);
	vec.color.green = ((double)((int)(C_GREEN(p2.color)
		- C_GREEN(p1.color)))) / ((double)vec.iter);
	vec.color.red = ((double)((int)(C_RED(p2.color)
		- C_RED(p1.color)))) / ((double)vec.iter);
	vec.line[0] = p1;
	vec.line[1] = p2;
	return (vec);
}
