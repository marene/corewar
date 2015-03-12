/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 05:38:20 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 05:38:21 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_list	*g_process;

void			fork_process(t_process *p, int dist)
{
	t_process	proc;
	t_list		*new;

	ft_memcpy(&proc, p, sizeof(t_process));
	proc.in_op = 0;
	proc.ct = 0;
	proc.reg.pc += dist;
	if (proc.reg.pc >= MEM_SIZE)
		proc.reg.pc %= MEM_SIZE;
	else if (proc.reg.pc < 0)
		proc.reg.pc = MEM_SIZE + (proc.reg.pc % MEM_SIZE);
	if (!(new = ft_lstnew(&proc, sizeof(t_process))))
	{
		perror("corewar");
		exit(1);
	}
	N_PROC++;
	get_arena()->data[proc.reg.pc].n_proc++;
	proc.player->n_proc++;
	ft_lstadd(&g_process, new);
	exec_process(new->content);
}

void			add_process(long pc, t_player *p)
{
	t_list		*new;
	t_process	proc;

	if (pc >= MEM_SIZE)
		pc %= MEM_SIZE;
	else if (pc < 0)
		pc = MEM_SIZE + (pc % MEM_SIZE);
	ft_bzero(&proc, sizeof(t_process));
	proc.player = p;
	proc.reg.pc = pc;
	if (!(new = ft_lstnew(&proc, sizeof(t_process))))
	{
		perror("corewar");
		exit(1);
	}
	ft_lstadd(&g_process, new);
	N_PROC++;
	proc.player->n_proc++;
	get_arena()->data[proc.reg.pc].n_proc++;
}


t_list			**get_process_lst(void)
{
	return (&g_process);
}
