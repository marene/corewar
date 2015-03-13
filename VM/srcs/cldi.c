/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 10:24:26 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 10:24:27 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cldi(t_process *p)
{
	long	dst;

	dst = cget_arg(1) + cget_arg(2);
	if (dst >= IDX_MOD || dst <= -IDX_MOD)
		dst %= IDX_MOD;
	cset_arg(3, CGET_MEM(p->reg.pc + dst, int));
	return (0);
}
