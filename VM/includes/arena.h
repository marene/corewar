/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 04:49:50 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 04:49:50 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include "corewar.h"

typedef struct			s_arena_data
{
	unsigned			n_proc;
	unsigned			color;
}						t_arena_data;

typedef struct			s_arena
{
	t_byte				mem[MEM_SIZE + 1];
	t_arena_data		data[MEM_SIZE + 1];
	t_byte				buf[MEM_SIZE];
}						t_arena;

# define CGET_MEM(pos, type) (*((type *)cget_mem(pos, sizeof(type))))
# define CSET_MEM(p, v, c, t) (cset_mem(p, (t_byte *)&v, c, sizeof(t)))

void					init_arena(void);
t_arena					*get_arena(void);
void					*cget_mem(long pos, unsigned size);
void					cset_mem(long pos, t_byte *value, unsigned c
							, unsigned size);
void					del_arena(void);

#endif
