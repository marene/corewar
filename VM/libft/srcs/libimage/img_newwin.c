/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_newwin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 15:50:17 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/08 15:50:18 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libimage.h"

static unsigned int		**alloc_img(void *img_ptr, int h, int w)
{
	int					i;
	unsigned int		**pix;

	if (!(pix = malloc(sizeof(int *) * h)))
		return (NULL);
	if (!(*pix =
		(unsigned int *)mlx_get_data_addr(img_ptr, &i, &i, &i)))
		return (free(pix), NULL);
	i = 1;
	while (i < h)
	{
		pix[i] = pix[i - 1] + w;
		i++;
	}
	return (pix);
}

static int				init_winsurface(t_surface *surface, int w, int h)
{
	if (!(surface->img = mlx_new_image(MLX_PTR, w, h)))
		return (-1);
	if (!(surface->pix = alloc_img(surface->img, h, w)))
	{
		mlx_destroy_image(MLX_PTR, surface->img);
		return (-1);
	}
	surface->h = h;
	surface->w = w;
	return (0);
}

t_win					*img_newwin(int w, int h, const char *name)
{
	t_win	*win;

	if (!MLX_PTR || w <= 0 || h <= 0)
		return (NULL);
	if (!(win = malloc(sizeof(t_win))))
		return (NULL);
	if (!(win->win_ptr = mlx_new_window(MLX_PTR, w, h, (char *)name)))
	{
		free(win);
		return (NULL);
	}
	if (init_winsurface(&win->screen, w, h) == -1)
	{
		mlx_destroy_window(MLX_PTR, win->win_ptr);
		free(win);
		return (NULL);
	}
	return (win);
}
