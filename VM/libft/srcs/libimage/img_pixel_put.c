/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 16:08:03 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/08 16:08:04 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimage.h"

void	img_pixel_put(void *surface, unsigned int color, int x, int y)
{
	t_surface	*ptr;

	ptr = surface;
	if (x < 0 || x > ptr->w || y < 0 || y > ptr->h || !ptr)
		return ;
	ptr->pix[y][x] = color;
}
