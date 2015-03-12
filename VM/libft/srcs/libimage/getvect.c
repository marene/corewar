/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getvect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 17:03:07 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/08 17:03:08 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimage.h"

t_vect	getvect(t_point p1, t_point p2)
{
	t_point	dif;
	t_vect	vec;

	dif = setpoint(p2.x - p1.y, p2.y - p1.y);
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
	vec.line[0] = p1;
	vec.line[1] = p2;
	return (vec);
}
