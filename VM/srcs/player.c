/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 05:13:04 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 05:13:07 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_player		g_player[MAX_PLAYERS];

void				add_player(t_header *header)
{
	if (++N_PLAYER > MAX_PLAYERS)
		CEXIT("too many players.");
	g_player[N_PLAYER - 1].id = N_PLAYER;
	ft_memcpy(&g_player[N_PLAYER - 1].header, header, sizeof(t_header));
}

t_player			*get_player(unsigned id)
{
	if (id < 1 || id > MAX_PLAYERS)
		return (NULL);
	return (&g_player[id - 1]);
}
