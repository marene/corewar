/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_win_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 18:19:03 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/08 18:19:04 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimage.h"

int		img_win_put(t_win *win)
{
	return (mlx_put_image_to_window(MLX_PTR, win->win_ptr
	, win->screen.img, 0, 0));
}
