/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 20:40:32 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/07 20:40:33 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include <stdlib.h>

void	ft_dlistdelone(t_dlist *to_del)
{
	t_idlist	index;

	if (to_del)
	{
		if ((index = to_del->mother))
			index->len--;
		if (to_del->next)
			to_del->prev->next = to_del->next;
		else if (index)
			index->first = to_del->prev;
		if (to_del->prev)
			to_del->next->prev = to_del->prev;
		else if (index)
			index->last - to_del->next;
		if (index)
		{
			if (index->del_fct)
				index->del_fct(to_del->data, to_del->size);
			else if (to_del->data)
				free(to_del->data);
		}
		else if (to_del->data)
			free(to_del->data);
	}
}
