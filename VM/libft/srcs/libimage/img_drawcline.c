/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_drawcline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 18:01:53 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/08 18:01:53 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimage.h"
#include <stdio.h>

static unsigned int	get_color__(t_color color)
{
	return (((unsigned int)color.blue) | (((unsigned int)color.green) << 8)
	| (((unsigned int)color.red) << 16));
}

void				img_drawcline(void *surface, t_cpoint p1, t_cpoint p2)
{
	t_cvect		vec;
	t_color		c;
	double		x;
	double		y;
	int			i;

	vec = getcvect(p1, p2);
	i = 0;
	c.blue = C_BLUE(p1.color);
	c.green = C_GREEN(p1.color);
	c.red = C_RED(p1.color);
	x = p1.x;
	y = p1.y;
	while (i++ < vec.iter)
	{
		img_pixel_put(surface, get_color__(c), x, y);
		x += vec.x;
		y += vec.y;
		c.blue += vec.color.blue;
		c.green += vec.color.green;
		c.red += vec.color.red;
	}
}
