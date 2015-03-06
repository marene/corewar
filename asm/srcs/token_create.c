/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/09 12:16:55 by marene            #+#    #+#             */
/*   Updated: 2015/02/24 17:39:35 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_token			*token_create(char *content, int value, t_type type, int size)
{
	t_token		*new;

	new = NULL;
	if ((new = (t_token*)malloc(sizeof(t_token))) != NULL)
	{
		new->content = ft_strdup(content);
		new->value = value;
		new->type = type;
		new->size = size;
		new->arg_nb = 0;
		new->next = NULL;
		new->args = NULL;
		new->linum = 0;
		new->addr = 0;
	}
	return (new);
}
