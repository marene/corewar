/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_ind_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 16:44:59 by marene            #+#    #+#             */
/*   Updated: 2016/02/19 15:51:30 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <error.h>
#include <op.h>

int				gen_ind_label(t_token *flow, t_env *env)
{
	char		*cont;
	t_token		*new_token;

	cont = NULL;
	if (env->begin < env->end
			&& (cont = ft_strsub(env->line, env->begin, env->end - env->begin)))
	{
		if ((new_token = token_create(cont, -1, T_IND_LABEL, IND_SIZE * BYTE)))
		{
			free(cont);
			return (add_to_flow(env, flow, new_token));
		}
		else
			set_serror(env, UNKNOWN_SERROR);
	}
	else
		set_serror(env, UNKNOWN_SERROR);
	return (ASM_KO);
	free(cont);
}
