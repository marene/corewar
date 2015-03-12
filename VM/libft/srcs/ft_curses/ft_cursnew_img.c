/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursnew_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 00:09:36 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/18 00:09:37 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_curses.h"

t_cimg		*ft_cursnew_img(int h, int w)
{
	t_cimg		*new;
	int			i;

	if (!(new = malloc(sizeof(t_cimg))))
		return (NULL);
	if (!(new->pix = malloc(sizeof(t_cpix *) * w)))
		return (free(new), NULL);
	if (!(*new->pix = ft_memmalloc(sizeof(t_cpix) * w * h)))
		return (free(new->pix), free(new), NULL);
	i = 1;
	new->w = w;
	new->h = h;
	while (i < w)
	{
		new->pix[i] = new->pix[i - 1];
		i++;
	}
	return (new);
}
