/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 18:00:04 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/08 18:00:05 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libimage.h"

void	set_cline(t_cline line, t_cpoint p1, t_cpoint p2)
{
	line[0].x = p1.x;
	line[0].y = p1.y;
	line[0].color = p1.color;
	line[1].x = p2.x;
	line[1].y = p2.y;
	line[1].color = p2.color;
}
