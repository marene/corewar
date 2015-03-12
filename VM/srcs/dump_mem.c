/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 08:08:14 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 08:08:15 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		put_hexa(t_byte byte)
{
	static char		base[] = "0123456789abcdef";

	ft_putchar(base[byte >> 4]);
	ft_putchar(base[byte & 15]);
}

void			dump_mem(void)
{
	unsigned	i;
	unsigned	j;
	unsigned	pos;
	t_arena		*arena;

	arena = get_arena();
	pos = 0;
	j = 0;
	while (pos < MEM_SIZE)
	{
		i = 0;
		while (i < 32 && pos < MEM_SIZE)
		{
			put_hexa(arena->mem[pos++]);
			i++;
			ft_putchar(i == 32 || pos == MEM_SIZE ? '\n' : ' ');
		}
		j++;
	}
	ft_flush_stdout();
	exit(1);
}
