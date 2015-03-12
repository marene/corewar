/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 01:18:09 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/05 01:18:10 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned		rev_u(t_byte *n)
{
	unsigned		i;
	unsigned		nb;
	t_byte			*p;

	p = (t_byte *)&nb;
	i = 0;
	while (i < sizeof(unsigned))
	{
		p[i] = n[sizeof(unsigned) - 1 - i];
		i++;
	}
	return (nb);
}

static void		ckill_process(t_list **lst, t_process *p)
{
	p->player->n_proc--;
	N_PROC--;
	get_arena()->data[p->reg.pc].n_proc--;
	ft_lstdelone(lst, NULL);
}

static void		reset_player(void)
{
	unsigned	i;

	i = 1;
	while (i <= N_PLAYER)
	{
		get_player(i)->cur_live = 0;
		i++;
	}
}

static void		check_process(void)
{
	unsigned	i;
	t_process	*p;
	t_list		**cur;

	cur = get_process_lst();
	i = 0;
	while (*cur)
	{
		p = (*cur)->content;
		if (!p->cur_live)
			ckill_process(cur, p);
		else
		{
			p->cur_live = 0;
			cur = &(*cur)->next;
			i++;
		}
	}
}

void			check(void)
{
	static unsigned	ct_check;

	CYCLE++;
	CT_CYCLE++;
	if (CT_CYCLE >= CTD)
	{
		ct_check++;
		if (ct_check >= MAX_CHECKS || N_LIVE >= NBR_LIVE)
		{
			ct_check = 0;
			CTD -= CYCLE_DELTA;
		}
		N_LIVE = 0;
		CT_CYCLE = 0;
		check_process();
		reset_player();
	}
	if (g_dump_value && CYCLE >= g_dump_value)
		dump_mem();
}
