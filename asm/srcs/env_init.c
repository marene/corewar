/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 10:30:28 by marene            #+#    #+#             */
/*   Updated: 2015/02/27 14:03:32 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <asm.h>
#include <error.h>

static t_syntax		*syntax_init(void)
{
	t_syntax	*ret;

	if ((ret = (t_syntax *)malloc(sizeof(t_syntax))) != NULL)
	{
		ret->serror = NO_SERROR;
		ret->linum = 0;
		ret->colnum = 0;
	}
	return (ret);
}

t_env				*env_init(void)
{
	t_env		*ret;
	t_syntax	*syntax;

	ret = NULL;
	if ((syntax = syntax_init())
			&& (ret = (t_env *)malloc(sizeof(t_env))) != NULL)
	{
		ret->line = NULL;
		ret->begin = 0;
		ret->end = 0;
		ret->name = 0;
		ret->comment = 0;
		ret->current_state = BEGIN;
		ret->next_state = NOS;
		ret->syntax = syntax;
	}
	return (ret);
}
