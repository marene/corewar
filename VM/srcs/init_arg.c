/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 08:50:16 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 08:50:16 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static unsigned		g_arg_len_tab[5][2] =
{
	{0, 0},
	{1, 1},
	{4, 2},
	{2, 2},
	{0, 0}
};

static int			get_arg_value(int pos, t_arg_type type, char has_idx)
{
	if (type == REG_CODE)
		return ((int)CGET_MEM(pos, t_byte));
	else if (type == IND_CODE || (type == DIR_CODE && has_idx))
		return (((int)CGET_MEM(pos, short)));
	else if (type == DIR_CODE)
		return (CGET_MEM(pos, int));
	return (0);
}

static unsigned		get_arg_len(char has_idx, t_arg_type type)
{
	return (g_arg_len_tab[type][(int)has_idx]);
}

static unsigned		init_value(t_process *p, t_arg_type type[], int value[])
{
	char		has_idx;
	unsigned	i;
	unsigned	len;

	len = p->cur_op->has_opc ? 2 : 1;
	i = 0;
	has_idx = p->cur_op->has_idx;
	while (i < p->cur_op->n_arg)
	{
		value[i] = get_arg_value(p->reg.pc + len, type[i], has_idx);
		if (!type[i]
			|| (type[i] == REG_CODE && (!(p->cur_op->arg_flag[i] & T_REG)))
			|| (type[i] == IND_CODE && (!(p->cur_op->arg_flag[i] & T_IND)))
			|| (type[i] == DIR_CODE && (!(p->cur_op->arg_flag[i] & T_DIR)))
			|| (type[i] == REG_CODE && (value[i] < 1 || value[i] > REG_NUMBER)))
			p->error = 1;
		len += get_arg_len(has_idx, type[i]);
		i++;
	}
	return (len);
}

static void			init_type(t_process *p, t_arg_type type[])
{
	unsigned	i;
	t_byte		opc;

	ft_bzero(type, sizeof(t_arg_type) * MAX_ARGS_NUMBER);
	if (!p->cur_op->has_opc)
	{
		type[0] = DIR_CODE;
		return ;
	}
	opc = CGET_MEM(p->reg.pc + 1, t_byte);
	i = MAX_ARGS_NUMBER;
	while (i-- > 0)
	{
		type[i] = opc & 3;
		opc >>= 2;
	}
}

unsigned			init_arg(t_process *p, t_arg_type type[], int value[])
{
	init_type(p, type);
	return (init_value(p, type, value));
}
