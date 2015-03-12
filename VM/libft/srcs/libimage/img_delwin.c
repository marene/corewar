/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_delwin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 15:57:21 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/08 15:57:22 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libimage.h"

void	img_delwin(t_win *win)
{
	if (win->win_ptr)
		mlx_destroy_window(MLX_PTR, win->win_ptr);
	if (win->screen.img)
		mlx_destroy_image(MLX_PTR, win->screen.img);
	if (win->screen.pix)
		free(win->screen.pix);
}
