/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_opcode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 13:26:36 by marene            #+#    #+#             */
/*   Updated: 2015/02/14 15:31:59 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <error.h>
#include <op.h>

extern t_op		g_op_table[17];

static int		get_op_value(char *op)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(g_op_table[i].mnemon, op) == 0)
			return (g_op_table[i].op_val);
		++i;
	}
	return (0);
}

int				gen_opcode(t_token *flow, t_env *env)
{
	char		*cont;
	int			value;
	t_token		*new_op;

	if (env->begin < env->end
			&& (cont = ft_strsub(env->line, env->begin, env->end - env->begin)))
	{
		if ((value = get_op_value(cont)) != 0)
		{
			if ((new_op = token_create(cont, value, T_OPCODE, OP_SIZE * BYTE)))
				return (add_to_flow(env, flow, new_op));
			else
				set_serror(env, UNKNOWN);
		}
		else
			set_serror(env, U_OPCODE);
	}
	else
		set_serror(env, UNKNOWN);
	return (ASM_KO);
}
