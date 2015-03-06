/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_flow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/28 12:37:14 by marene            #+#    #+#             */
/*   Updated: 2015/02/27 11:30:35 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <op.h>
#include <error.h>

extern t_op		g_op_table[17];

static int		get_token_addr(t_token *flow)
{
	t_token		*args;
	int			addr;

	addr = 0;
	while (flow)
	{
		args = flow->args;
		addr += flow->size;
		if (flow->type == T_OPCODE && g_op_table[flow->value - 1].encoding_byte)
			++addr;
		while (args)
		{
			addr += args->size;
			args = args->args;
		}
		flow = flow->next;
	}
	return (addr);
}

static int		add_new_arg(t_env *env, t_token *flow, t_token *new)
{
	if (flow->arg_nb < 3)
	{
		if ((g_op_table[flow->value - 1].args[flow->arg_nb] & T_INDEX) != 0
				&& new->type != T_REGISTER)
			new->size = IND_SIZE;
	}
	else
	{
		set_serror(env, W_PARAM_NB);
		return (ASM_KO);
	}
	++(flow->arg_nb);
	while (flow->args != NULL)
		flow = flow->args;
	flow->args = new;
	return (ASM_OK);
}

int				add_to_flow(t_env *env, t_token *flow, t_token *new)
{
	new->addr = get_token_addr(flow);
	if (env && env->syntax)
		new->linum = env->syntax->linum;
	while (flow->next)
		flow = flow->next;
	if (new->type == T_OPCODE || new->type == T_STDA_LABEL
			|| new->type == T_NAME || new->type == T_COM || new->type == T_NAME)
	{
		flow->next = new;
		return (ASM_OK);
	}
	else if (flow->type == T_OPCODE && add_new_arg(env, flow, new) == ASM_OK)
		return (ASM_OK);
	else
		set_serror(env, U_TOKEN);
	return (ASM_KO);
}
