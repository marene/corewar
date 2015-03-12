/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idlistdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 20:47:36 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/07 20:47:37 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"
#include <stdlib.h>

void	ft_idlistdel(t_idlist **to_del)
{
	void		(*del_fct)(void *, size_t);
	t_dlist		*cur;
	t_dlist		*prev;

	if (!to_del || !*to_del)
		return ;
	del_fct = (*to_del)->del_fct;
	cur = (*to_del)->last;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		if (del_fct)
			del_fct(prev->data, prev->size);
		else if (prev->data)
			free(prev->data);
		free (prev);
	}
	free (*to_del);
	*to_del = NULL;
}
