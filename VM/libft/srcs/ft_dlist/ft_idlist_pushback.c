/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idlist_pushback.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 20:33:33 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/07 20:33:35 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_dlist.h"

void	ft_idlist_pushback(t_idlist *index, t_dlist *new)
{
	if (new && index)
	{
		if (index->last)
			index->last->prev = new;
		else
			index->first = new;
		new->next = index->last;
		index->last = new;
		new->mother = index;
		index->len++;
	}
}
