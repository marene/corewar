/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 05:09:11 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 05:09:13 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "corewar.h"

typedef struct	s_player
{
	unsigned	id;
	unsigned	n_proc;
	unsigned	cur_live;
	unsigned	last_live;
	t_header	header;
}				t_player;

void			add_player(t_header *header);
t_player		*get_player(unsigned id);

#endif
