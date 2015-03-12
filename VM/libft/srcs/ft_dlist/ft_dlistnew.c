/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 20:23:05 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/07 20:23:05 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_dlist.h"

t_dlist		*ft_dlistnew(void *data, size_t size, int flag)
{
	t_dlist		*new;

	if (!(new = malloc(sizeof(t_dlist))))
		return (NULL);
	new->size = data ? size : 0;
	if (!new->size)
		new->data = NULL;
	else if (flag == ALLOC_DATA)
	{
		if (!(new->data = malloc(size)))
		{
			FT_ERRNO = FT_ENOMEM;
			free(new);
			return (NULL);
		}
		ft_memcpy(new->data, data, size);
	}
	else
		new->data = data;
	new->mother = NULL;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
