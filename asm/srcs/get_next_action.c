/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 11:09:26 by marene            #+#    #+#             */
/*   Updated: 2016/02/19 15:49:54 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <error.h>
#include <states.h>

extern t_fct_ptr	g_action_table;
extern int			g_state_table[17][12][2];

int					get_next_action(t_env *env, t_symbol symbol, t_act_fct *fct)
{
	t_action		action;

	if ((env->next_state = g_state_table[env->current_state][symbol][0]) != NOS)
	{
		if ((action = g_state_table[env->current_state][symbol][1]) != NOA)
		{
			env->current_state = env->next_state;
			if ((*fct = g_action_table[action]) != NULL)
				return (ASM_OK);
		}
		else
			*fct = NULL;
		if ((env->current_state != env->next_state || symbol == WHITE_SPACE)
				&& env->next_state != BEG_STDA_LABEL
				&& env->next_state != STDA_LABEL
				&& env->current_state != BEG_IND_NUM)
			env->begin = env->end;
		env->current_state = env->next_state;
		return (ASM_OK);
	}
	else
		set_serror(env, U_SYMBOL);
	return (ASM_KO);
}
