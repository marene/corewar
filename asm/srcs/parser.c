/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 11:56:23 by marene            #+#    #+#             */
/*   Updated: 2015/03/09 17:49:12 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <error.h>
#include <op.h>

extern t_op		g_op_table[17];

t_arg_type			get_argtype(t_type arg)
{
	if (arg > T_OPCODE && arg < T_REGISTER)
		return (T_IND);
	else if (arg == T_REGISTER)
		return (T_REG);
	else
		return (T_DIR);
}

static t_token		*get_head(t_token *flow)
{
	while (flow && (flow->type == T_BEGIN || flow->type == T_NAME
				|| flow->type == T_COM))
		flow = flow->next;
	return (flow);
}

static int			replace_label(t_env *env, t_token *head, t_token *flow,
		t_token *args)
{
	while (head)
	{
		if (head->type == T_STDA_LABEL
				&& ft_strcmp(head->content, args->content) == 0)
		{
			args->value = head->addr - flow->addr;
			return (ASM_OK);
		}
		head = head->next;
	}
	set_serror(env, U_LABEL);
	return (ASM_KO);
}

static int			check_args(t_env *env, t_token *head, t_token *flow)
{
	t_op			op;
	int				arg_nb;
	t_token			*args;

	arg_nb = 0;
	op = g_op_table[flow->value - 1];
	args = flow->args;
	if (flow->arg_nb != op.arg_nb && set_serror(env, W_PARAM_NB) != NULL)
		return (ASM_KO);
	while (args)
	{
		if ((args->type == T_DIR_LABEL || args->type == T_IND_LABEL)
				&& (replace_label(env, head, flow, args)) == ASM_KO)
			return (ASM_KO);
		if ((op.args[arg_nb++] & get_argtype(args->type)) == 0)
		{
			set_serror(env, W_PARAM_TYPE);
			return (ASM_KO);
		}
		env->syntax->colnum += ft_strlen(args->content) + 2;
		env->syntax->colnum += (args->type >= T_REGISTER
				&& args->type < T_STDA_LABEL) ? 1 : 0;
		args = args->args;
	}
	return (ASM_OK);
}

int					parser(t_token *flow)
{
	t_token		*head;
	t_env		*env;

	if (flow && (env = env_init()))
	{
		head = get_head(flow);
		flow = head;
		while (flow)
		{
			env->syntax->linum = flow->linum;
			env->syntax->colnum = ft_strlen(flow->content) + 1;
			env->line = make_line(flow);
			if ((flow->type == T_OPCODE
						&& check_args(env, head, flow) == ASM_KO))
			{
				env_delete(&env);
				return (ASM_KO);
			}
			free(env->line);
			env->line = NULL;
			flow = flow->next;
		}
	}
	env_delete(&env);
	return (ASM_OK);
}
