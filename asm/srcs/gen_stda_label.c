/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_stda_label.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 16:46:14 by marene            #+#    #+#             */
/*   Updated: 2015/02/24 17:12:11 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <error.h>
#include <op.h>

int				gen_stda_label(t_token *flow, t_env *env)
{
	char		*cont;
	t_token		*new;

	if (env->begin < env->end
		&& (cont = ft_strsub(env->line, env->begin, env->end - env->begin)))
	{
		if ((new = token_create(cont, 0, T_STDA_LABEL, 0)))
			return (add_to_flow(env, flow, new));
		else
			set_serror(env, UNKNOWN);
	}
	else
		set_serror(env, UNKNOWN);
	return (ASM_KO);
}
