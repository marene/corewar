/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 14:56:34 by marene            #+#    #+#             */
/*   Updated: 2015/03/11 12:12:19 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <libft.h>
#include <op.h>
#include <cdb.h>

t_op	g_op_table[17] =
{
	{"live", 1, {T_DIR, 0, 0}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG, 0}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG, 0}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_INDEX | T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_INDEX | T_REG | T_DIR | T_IND, T_INDEX | T_DIR | T_REG,
			T_REG}, 10, 25, "load index", 1, 1},
	{"sti", 3, {T_REG, T_INDEX | T_REG | T_DIR | T_IND, T_INDEX | T_DIR
			| T_REG}, 11, 25, "store index", 1, 1},
	{"fork", 1, {T_INDEX | T_DIR, 0, 0}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG, 0}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_INDEX | T_REG | T_DIR | T_IND, T_INDEX | T_DIR | T_REG,
			T_REG}, 14, 50, "long load index", 1, 1},
	{"lfork", 1, {T_INDEX | T_DIR, 0, 0}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG, 0, 0}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

static int		is_valid_cor(int fd)
{
	t_header	head;

	if (read(fd, &head, sizeof(t_header)) == sizeof(t_header))
	{
		if (change_endianess(head.magic) == COREWAR_EXEC_MAGIC && head.prog_name[0]
				&& head.comment[0])
		{
			ft_putstr(".name \"");
			ft_putstr(head.prog_name);
			ft_putendl("\"");
			ft_putstr(".comment \"");
			ft_putstr(head.comment);
			ft_putendl("\"");
			return (CDB_OK);
		}
	}
	return (CDB_KO);
}

int				main(int argc, char **argv)
{
	int		i;
	int		fd;

	i = 1;
	while (i < argc)
	{
		ft_putendl(argv[i]);
		if ((fd = open(argv[i], O_RDONLY)) >= 0)
		{
			if (is_valid_cor(fd) == CDB_OK)
				disassemble(fd);
			else
				ft_putendl("not a valid .cor");
			close(fd);
		}
		++i;
	}
	return (0);
}
