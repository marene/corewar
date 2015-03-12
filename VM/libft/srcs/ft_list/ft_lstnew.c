/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:20:19 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/05 15:19:09 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_elem;

	if (!(new_elem = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new_elem->next = NULL;
	if (!content)
	{
		new_elem->content = NULL;
		new_elem->content_size = 0;
	}
	else
	{
		if (!(new_elem->content = malloc(content_size)))
			return (NULL);
		new_elem->content = ft_memcpy(new_elem->content, content, content_size);
		new_elem->content_size = content_size;
	}
	return (new_elem);
}
