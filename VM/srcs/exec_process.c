/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 08:06:33 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 08:06:34 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		(*g_cfct[])(t_process *) =
{
	NULL,
	&clive,
	&cld,
	&cst,
	&cadd,
	&csub,
	&cand,
	&cor,
	&cxor,
	&czjmp,
	&cldi,
	&csti,
	&cfork,
	&clld,
	&clldi,
	&clfork,
	&caff
};

void			exec_process(t_process *p)
{
	t_byte		op_id;
	unsigned	op_len;

	if (!p->in_op)
	{
		op_id = CGET_MEM(p->reg.pc, t_byte);
		if (OP_OK(op_id))
		{
			p->in_op = 1;
			p->cur_op = &g_op_tab[(unsigned)op_id - 1];
			p->ct = p->cur_op->cost;
		}
		else
			move_process(p, 1);
	}
	if (p->in_op)
	{
		if (!p->ct)
		{
			p->error = 0;
			op_len = load_arg(p);
			if (p->error)
				move_process(p, op_len);
			else if (!(g_cfct[p->cur_op->id](p)))
				move_process(p, op_len);
			p->in_op = 0;
		}
		else
			p->ct--;
	}
}
