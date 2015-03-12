/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 10:22:55 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 10:22:56 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cand(t_process *p)
{
	int		result;

	(void)p;
	result = cget_arg(1) & cget_arg(2);
	cset_arg(3, result);
	p->reg.carry = result == 0;
	return (0);
}
