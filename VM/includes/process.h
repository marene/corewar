/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 05:38:34 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 05:38:36 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "corewar.h"

# define LAST_PROC (((t_process *)(*get_process_lst())->content))

typedef struct		s_proc_register
{
	int				r[REG_NUMBER];
	char			carry;
	long			pc;
}					t_reg;

typedef struct		s_process
{
	unsigned		cur_live;
	char			in_op;
	char			error;
	unsigned		ct;
	t_reg			reg;
	t_op			*cur_op;
	t_player		*player;
}					t_process;

void				add_process(long pc, t_player *p);
t_list				**get_process_lst(void);
void				move_process(t_process *p, long dist);
void				push_process(void);
void				exec_process(t_process *p);

void				fork_process(t_process *p, int dist);

#endif
