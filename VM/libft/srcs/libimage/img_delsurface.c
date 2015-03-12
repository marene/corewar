/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_delsurface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 16:01:26 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/08 16:01:27 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libimage.h"

void	img_delsurface(t_surface *surface)
{
	if (surface->img)
		mlx_destroy_image(MLX_PTR, surface->img);
	if (surface->pix)
		free(surface->pix);
}
