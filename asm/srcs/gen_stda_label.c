/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_stda_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 16:46:14 by marene            #+#    #+#             */
/*   Updated: 2016/02/19 16:12:58 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <error.h>
#include <op.h>

int				gen_stda_label(t_token *flow, t_env *env)
{
	char		*cont;
	t_token		*new;

	cont = NULL;
	if (env->begin < env->end
		&& (cont = ft_strsub(env->line, env->begin, env->end - env->begin)))
	{
		if ((new = token_create(cont, 0, T_STDA_LABEL, 0)))
		{
			free(cont);
			return (add_to_flow(env, flow, new));
		}
		else
			set_serror(env, UNKNOWN_SERROR);
	}
	else
		set_serror(env, UNKNOWN_SERROR);
	free(cont);
	return (ASM_KO);
}
