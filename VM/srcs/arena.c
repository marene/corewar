/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 04:49:40 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 04:49:41 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_arena	*g_arena;

void			init_arena(void)
{
	if (!(g_arena = ft_memalloc(sizeof(t_arena))))
	{
		perror("corewar");
		exit(1);
	}
}

t_arena			*get_arena(void)
{
	return (g_arena);
}

void			cset_mem(long pos, t_byte *value, unsigned c, unsigned size)
{
	if (pos < 0)
		pos = MEM_SIZE + (pos % MEM_SIZE);
	else if (pos >= MEM_SIZE)
		pos %= MEM_SIZE;
	while (size-- > 0)
	{
		g_arena->data[pos].color = c;
		g_arena->mem[pos] = value[size];
		if (++pos == MEM_SIZE)
			pos = 0;
	}
}

void			*cget_mem(long pos, unsigned size)
{
	unsigned	i;

	i = size;
	if (pos < 0)
		pos = MEM_SIZE + (pos % MEM_SIZE);
	else if (pos >= MEM_SIZE)
		pos %= MEM_SIZE;
	while (i > 0)
	{
		i--;
		g_arena->buf[i] = g_arena->mem[pos];
		if (++pos == MEM_SIZE)
			pos = 0;
	}
	return ((void *)g_arena->buf);
}

void			del_arena(void)
{
	free(g_arena);
}
