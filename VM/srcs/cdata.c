/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdata.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 06:48:26 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 06:48:27 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

long			g_n_player;
long			g_n_proc;
long			g_cycle;
long			g_cycle_to_die;
long			g_ct_cycle;
long			g_cflag;
long			g_n_live;
long			g_dump_value;

void			init_data(void)
{
	CTD = CYCLE_TO_DIE;
}
