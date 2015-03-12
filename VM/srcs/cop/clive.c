/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clive.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 10:24:07 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 10:24:08 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		clive(t_process *p)
{
	t_player	*player;

	p->cur_live++;
	N_LIVE++;
	if ((player = get_player(cget_arg(1))))
	{
		player->cur_live++;
		player->last_live = CYCLE;
		p->player = player;
		if (!HAS_VIDEO && !HAS_DUMP)
		{
			ft_putstr("le joueur "), ft_putchar(player->id + '0');
			ft_putchar('('), ft_putstr(player->header.prog_name);
			ft_putchar(')'), ft_putstr(" est en vie\n");
		}
	}
	return (0);
}
