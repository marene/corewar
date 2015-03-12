/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clld.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 10:21:36 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 10:21:37 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		clld(t_process *p)
{
	int		value;

	(void)p;
	value = cget_arg(1);
	cset_arg(2, value);
	p->reg.carry = value == 0;
	return (0);
}
