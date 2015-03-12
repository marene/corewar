/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setcpoint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 17:16:36 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/08 17:16:36 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimage.h"

t_cpoint		setcpoint(int x, int y, unsigned int color)
{
	t_cpoint	p;

	p.x = x;
	p.y = y;
	p.color = color;
	return (p);
}
