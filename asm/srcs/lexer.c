/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 18:56:29 by marene            #+#    #+#             */
/*   Updated: 2015/03/05 14:31:18 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <asm.h>
#include <error.h>
#include <get_next_line.h>
#include <op.h>

static t_symbol		eval_symbol(char c)
{
	if (c == '-' || c == '+')
		return (SIGN_CHAR);
	else if (c >= 'a' && c <= 'z' && c != 'r')
		return (AB_CHARS);
	else if (c >= '0' && c <= '9')
		return (NUM_VAL);
	else if (c == C_SEPARATOR_CHAR)
		return (SEP_CHAR);
	else if (c == C_DIRECT_CHAR)
		return (DIR_CHAR);
	else if (c == C_LABEL_CHAR)
		return (LABEL_CHAR);
	else if (c == '\0')
		return (NEWLINE);
	else if (ft_strchr(C_LABEL_CHARS, c) != NULL)
		return (LABEL_CHARS);
	else if (c == 'r')
		return (REG_CHAR);
	else if (c == ' ' || c == '\t')
		return (WHITE_SPACE);
	else if (c == C_COMMENT_CHAR)
		return (COMMENT_CHAR);
	else
		return (END);
}

static int			lexe_next_line(t_env *env, t_token *flow)
{
	int			len;
	t_symbol	symbol;
	int			(*action) (t_token *flow, t_env *env);

	action = NULL;
	len = ft_strlen(env->line);
	while (env->end <= len)
	{
		symbol = eval_symbol(env->line[env->end]);
		if (get_next_action(env, symbol, &action) == ASM_OK)
		{
			if (action != NULL)
				if (action(flow, env) != ASM_OK)
					return (ASM_KO);
		}
		else
			return (ASM_KO);
		++(env->end);
		++(env->syntax->colnum);
	}
	return (ASM_OK);
}

int					lexer(t_env *env, int fd, t_token *flow)
{
	action_table_init();
	while (get_next_line(fd, &(env->line)) == 1)
	{
		++(env->syntax->linum);
		env->syntax->colnum = 0;
		env->current_state = BEGIN;
		env->begin = 0;
		env->end = 0;
		if (lexe_next_line(env, flow) == ASM_KO)
			return (ASM_KO);
		free(env->line);
		env->line = NULL;
	}
	return (ASM_OK);
}
