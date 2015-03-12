/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clldi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 10:24:44 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 10:24:45 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		clldi(t_process *p)
{
	long	dst;

	dst = cget_arg(1) + cget_arg(2);
	cset_arg(3, CGET_MEM(p->reg.pc + dst, int));
	return (0);
}
