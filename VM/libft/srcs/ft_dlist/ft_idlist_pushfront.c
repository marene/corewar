/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idlist_pushfront.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 20:37:15 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/07 20:37:16 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_dlist.h"

void	ft_idlist_pushfront(t_idlist *index, t_dlist *new)
{
	if (new && index)
	{
		if (index->first)
			index->first->next = new;
		else
			index->last = new;
		new->prev = index->first;
		index->first = new;
		new->mother = index;
		index->len++;
	}
}
