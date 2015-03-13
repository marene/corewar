/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 08:06:48 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 08:06:50 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			move_process(t_process *p, long dist)
{
	get_arena()->data[p->reg.pc].n_proc--;
	p->reg.pc += dist;
	if (p->reg.pc >= MEM_SIZE)
		p->reg.pc %= MEM_SIZE;
	else if (p->reg.pc < 0)
		p->reg.pc = MEM_SIZE + (p->reg.pc % MEM_SIZE);
	get_arena()->data[p->reg.pc].n_proc++;
}
