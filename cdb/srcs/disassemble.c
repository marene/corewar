/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 15:08:38 by marene            #+#    #+#             */
/*   Updated: 2015/03/11 12:53:05 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <op.h>
#include <cdb.h>

# include <stdio.h>

extern t_op		g_op_table[17];

static void		print_encoding(unsigned char *encoding)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		ft_putstr(" [");
		ft_putnbr(encoding[i]);
		ft_putstr("] ");
		if ((encoding[i] & ~CDB_INDEX) == REG_CODE)
			ft_putstr(" register ");
		else if ((encoding[i] & ~CDB_INDEX) == DIR_CODE)
			ft_putstr(" direct ");
		else if ((encoding[i] & ~CDB_INDEX) == IND_CODE)
			ft_putstr(" indirect ");
		else if (encoding[i] != 0)
			ft_putstr(" unknown ");
		else
			ft_putstr(" - ");
		++i;
	}
	ft_putchar('\n');
}

static void		copy_op_args(t_op op, unsigned char *encoding)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if ((op.args[i] & T_REG) != 0)
			encoding[i] = REG_CODE;
		else if ((op.args[i] & T_DIR) != 0)
			encoding[i] = DIR_CODE;
		else if ((op.args[i] & T_IND) != 0)
			encoding[i] = IND_CODE;
		else
			encoding[i] = 0;
		if ((op.args[i] & T_INDEX) != 0)
			encoding[i] |= CDB_INDEX;
		++i;
	}
}

static int		get_encoding(int fd, t_op op, unsigned char *encoding)
{
	unsigned char	b;
	unsigned char	mask;
	unsigned char	shift;
	int				i;

	i = 0;
	mask = 0xc0;
	shift = 6;
	if (op.encoding_byte)
	{
		if (read(fd, &b, 1) > 0)
		{
			while (i < 3)
			{
				encoding[i] = (b & mask);
				encoding[i] = encoding[i] >> shift;
				if ((op.args[i] & T_INDEX) != 0)
					encoding[i] |= CDB_INDEX;
				else
					encoding[i] &= ~CDB_INDEX;
				mask = mask >> 2;
				shift -= 2;
				++i;
			}
		}
		else
			return (CDB_KO);
	}
	else
		copy_op_args(op, encoding);
	print_encoding(encoding);
	return (CDB_OK);
}

static int		get_op(int fd, char b, unsigned char *encoding)
{
	int		i;
	char	mask;

	i = 0;
	mask = 0x30;
	while (i < 16)
	{
		if (g_op_table[i].op_val == b)
		{
			ft_putstr(g_op_table[i].mnemon);
			ft_putstr(" ");
			if (get_encoding(fd, g_op_table[i], encoding) == CDB_OK)
				return (CDB_OK);
			else
				return (CDB_KO);
		}
		++i;
	}
	ft_putstr("invalid byte value <");
	ft_putnbr(b);
	ft_putendl(">");
	return (CDB_KO);
}

int				disassemble(int fd)
{
	char			b;
	unsigned char	encoding[3];

	while (read(fd, &b, 1) > 0)
	{
		ft_bzero(encoding, sizeof(unsigned char) * 3);
		if (encoding[0] || encoding[1] || encoding[2])
			ft_putendl("ENCODING NOT ZEROED!");
		if (get_op(fd, b, encoding) == CDB_OK)
		{
			if (get_args(fd, encoding) == CDB_KO)
				return (CDB_KO);
		}
		else
			return (CDB_KO);
	}
	return (CDB_OK);
}
