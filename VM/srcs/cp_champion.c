/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cp_champion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 00:43:25 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/05 00:43:26 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		cp_champion(t_champ *champ, long pos, unsigned c)
{
	t_arena		*arena;
	unsigned	i;

	arena = get_arena();
	i = 0;
	while (i < CHAMP_MAX_SIZE)
	{
		arena->mem[pos + i] = (*champ)[i];
		arena->data[pos + i].color = c;
		i++;
	}
}

