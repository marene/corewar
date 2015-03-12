/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 09:03:53 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 09:03:55 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_arg_type	g_type[MAX_ARGS_NUMBER];
static int			g_value[MAX_ARGS_NUMBER];
static t_process	*g_process;

unsigned			load_arg(t_process *p)
{
	g_process = p;
	return (init_arg(p, g_type, g_value));
}

t_arg_type			cget_type(int n)
{
	return (g_type[n - 1]);
}

int					cget_arg(int n)
{
	--n;
	if (g_type[n] == REG_CODE && g_value[n] >= 1 && g_value[n] <= REG_NUMBER)
		return (g_process->reg.r[g_value[n] - 1]);
	else if (g_type[n] == DIR_CODE)
		return (g_value[n]);
	else if (g_type[n] == IND_CODE)
		return (CGET_MEM(g_process->cur_op->is_mod
			? (g_value[n] % IDX_MOD)
			: g_value[n], int));
	return (0);
}

void				cset_arg(int n, int value)
{
	--n;
	if (g_type[n] == REG_CODE && g_value[n] >= 1 && g_value[n] <= REG_NUMBER)
		g_process->reg.r[g_value[n] - 1] = value;
	else if (g_type[n] == IND_CODE)
	{
		CSET_MEM(g_process->reg.pc + (g_process->cur_op->is_mod
			? (g_value[n] % IDX_MOD) : g_value[n])
			, value, g_process->player->id, int);
	}
}
