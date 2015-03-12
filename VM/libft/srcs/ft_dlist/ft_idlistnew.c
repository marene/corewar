/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idlistnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 20:31:47 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/07 20:31:48 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_dlist.h"

t_idlist	ft_idlistnew(void (*del_fct)(void *, size_t))
{
	t_idlist	*new;

	if (!(new = malloc(sizeof(t_idlist))))
	{
		FT_ERRNO = FT_ENOMEM;
		return (NULL);
	}
	new->first = NULL;
	new->last = NULL;
	new->del_fct = del_fct;
	new->len = 0;
	return (new);
}
