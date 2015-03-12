/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_newsurface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 15:38:34 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/08 15:38:36 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libimage.h"

static unsigned int		**alloc_img(void *img_ptr, int h, int w)
{
	int		i;
	int		**pix;

	if (!(pix = malloc(sizeof(int *) * h)))
		return (NULL);
	if (!(*(pix) =
		(int *)mlx_get_data_addr(img_ptr, &i, &i, &i)))
		return (free(pix), NULL);
	i = 1;
	while (i < h)
	{
		pix[i] = pix[i - 1] + w;
		i++;
	}
	return (0);
}

t_surface				*img_newsurface(int w, int h)
{
	t_surface	*new;

	if (h <= 0 || w <= 0 || !MLX_PTR)
		return (NULL);
	if (!(new = malloc(sizeof(t_surface))))
		return (NULL);
	if (!(new->img = mlx_new_image(MLX_PTR, w, h)))
		return (free(new), NULL);
	if (!(new->pix = alloc_img(new->img, h, w)))
	{
		mlx_destroy_image(MLX_PTR, new->img);
		return (NULL);
	}
	new->h = h;
	new->w = w;
	return (new);
}
