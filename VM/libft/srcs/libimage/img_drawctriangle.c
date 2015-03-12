/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_drawctriangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 00:51:27 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/09 00:51:28 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimage.h"
#include <stdio.h>

# define ADD_COLOR(A, B) (A.blue += B.blue, A.red += B.red, A.green += B.green)
# define SUB_COLOR(A, B) (A.blue -= B.blue, A.red -= B.red, A.green -= B.green)
# define CC_SETR(A, B) (A.red = (double)((int)C_RED(B)))
# define CC_SETG(A, B) (A.green = (double)((int)C_GREEN(B)))
# define CC_SETB(A, B) (A.blue = (double)((int)C_BLUE(B)))
# define SET_COLOR(C, X) (CC_SETR(C, X), CC_SETG(C, X), CC_SETB(C, X))

static unsigned int	get_color__(t_color color)
{
	return (((unsigned int)color.blue) | (((unsigned int)color.green) << 8)
	| (((unsigned int)color.red) << 16));
}

static t_cvect	getcvect2__(t_cpoint p1, t_cpoint p2)
{
	t_point	dif;
	t_cvect	vec;

	dif = setpoint(p2.x - p1.x, p2.y - p1.y);
	vec.y = dif.y > 0 ? 1.0 : -1.0;
	vec.x = (double)dif.x / ABS(dif.y);
	vec.iter = ABS(dif.y);
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

static t_cpoint	**sort_point(t_cpoint *p1, t_cpoint *p2, t_cpoint *p3)
{
	static t_cpoint		*p[3];
	int					i;
	t_cpoint			*p_ptr;

	p[0] = p1;
	p[1] = p2;
	p[2] = p3;

	i = 0;
	while (i < 2)
	{
		if (p[i]->y > p[i + 1]->y)
		{
			p_ptr = p[i];
			p[i] = p[i + 1];
			p[i + 1] = p_ptr;
			i = 0;
		}
		else
			i++;
	}
	return ((t_cpoint **)p);
}

static t_cvect	*get_vect__(t_cpoint **p)
{
	static t_cvect	vec[3];

	vec[0] = getcvect2__(*p[0], *p[1]);
	vec[1] = getcvect2__(*p[0], *p[2]);
	vec[2] = getcvect2__(*p[1], *p[2]);
	return ((t_cvect *)vec);	
}

static void			draw2__(void *surface, t_cvect *vec, t_cpoint **p, t_color *c)
{
	int			i;
	double		x[2];
	double		y;

	x[0] = p[2]->x;
	x[1] = p[2]->x;
	y = p[2]->y;
	i = 0;
	SET_COLOR(c[0], p[2]->color);
	SET_COLOR(c[1], p[2]->color);
	while (i < vec[1].iter && i++ < vec[2].iter)
	{
		img_drawcline(surface, setcpoint(x[0], y, get_color__(c[0])), setcpoint(x[1], y, get_color__(c[1])));
		SUB_COLOR(c[0], vec[2].color);
		SUB_COLOR(c[1], vec[1].color);
		x[0] -= vec[2].x;
		x[1] -= vec[1].x;
		y -= 1.0;
	}
}

static void			draw__(void *surface, t_cvect *vec, t_cpoint **p, t_color *c)
{
	int		i;
	double		x[2];
	double		y;

	x[0] = p[0]->x;
	x[1] = p[0]->x;
	y = p[0]->y;
	i = 0;
	SET_COLOR(c[0], p[0]->color);
	SET_COLOR(c[1], p[0]->color);
	while (i <= vec[0].iter && i++ <= vec[1].iter)
	{	
		img_drawcline(surface, setcpoint(x[0], y, get_color__(c[0])), setcpoint(x[1], y, get_color__(c[1])));
		ADD_COLOR(c[0], vec[0].color);
		ADD_COLOR(c[1], vec[1].color);
		x[0] += vec[0].x;
		x[1] += vec[1].x;
		y += 1.0;
	}
}

void			img_drawctriangle(void *surface, t_cpoint p1
					, t_cpoint p2, t_cpoint p3)
{
	t_cpoint	**p;
	t_cvect		*vec;
	t_color		c[2];

	p = sort_point(&p1, &p2, &p3);
	vec = get_vect__(p);
	draw__(surface, vec, p, c);
	draw2__(surface, vec, p, c);
}
