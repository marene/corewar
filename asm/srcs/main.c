/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 11:51:28 by marene            #+#    #+#             */
/*   Updated: 2015/03/09 17:47:29 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <op.h>
#include <asm.h>
#include <error.h>

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

char	*gettype(t_type t)
{
	if (t == T_BEGIN)
		return ("T_BEGIN");
	else if (t == T_NAME)
		return ("T_NAME");
	else if (t == T_COM)
		return ("T_COM");
	else if (t == T_OPCODE)
		return ("T_OPCODE");
	else if (t == T_IND_NUM)
		return ("T_IND_NUM");
	else if (t == T_IND_LABEL)
		return ("T_IND_LABEL");
	else if (t == T_REGISTER)
		return ("T_REGISTER");
	else if (t == T_DIR_NUM)
		return ("T_DIR_NUM");
	else if (t == T_DIR_LABEL)
		return ("T_DIR_LABEL");
	else if (t == T_STDA_LABEL)
		return ("T_STDA_LABEL");
	else
		return (NULL);
}

int		main(int argc, char **argv)
{
	t_env		*env;
	t_token		*flow;
	int			fd;

	if (argc == 2 && (env = env_init()) != NULL)
	{
		action_table_init();
		if ((fd = open(argv[1], O_RDONLY)) >= 0)
		{
			if ((flow = token_flow_init(env, argv[1], fd)) != NULL)
			{
				if (lexer(env, fd, flow) == ASM_KO || parser(flow) == ASM_KO)
					print_serror();
				else
					gen_cor(flow);
			}
			close(fd);
		}
		else
			set_error(W_FILE);
	}
	else
		set_error(W_USAGE);
	print_error();
	return (0);
}
