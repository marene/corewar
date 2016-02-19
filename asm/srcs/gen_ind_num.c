/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_ind_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 17:48:38 by marene            #+#    #+#             */
/*   Updated: 2016/02/19 15:50:57 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <error.h>
#include <op.h>

int				gen_ind_num(t_token *flow, t_env *env)
{
	char		*cont;
	int			value;
	t_token		*new;

	cont = NULL;
	if (env->begin < env->end
			&& (cont = ft_strsub(env->line, env->begin, env->end - env->begin)))
	{
		value = ft_atoi(cont);
		if ((new = token_create(cont, value, T_IND_NUM, IND_SIZE * BYTE)))
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
