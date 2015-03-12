/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 10:25:35 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 10:25:37 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		csti(t_process *p)
{
	long	dst;
	int		value;

	dst = cget_arg(2) + cget_arg(3);
	if (dst >= IDX_MOD || dst <= -IDX_MOD)
		dst %= IDX_MOD;
	value = cget_arg(1);
	CSET_MEM(p->reg.pc + dst, value, p->player->id, int);
	return (0);
}
