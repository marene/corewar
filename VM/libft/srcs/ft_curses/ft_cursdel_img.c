/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursdel_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 00:17:53 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/18 00:17:57 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_curses.h"

void	ft_cursdel_img(t_cimg *img)
{
	if (img)
	{
		if (img->pix)
		{
			if (*img->pix)
				free(*img->pix);
			free(img->pix);
		}
		free(img);
	}
}
