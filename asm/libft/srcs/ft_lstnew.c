/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 09:45:42 by marene            #+#    #+#             */
/*   Updated: 2013/12/22 21:07:55 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	if (content)
	{
		new_elem->content = malloc(content_size);
		ft_memcpy(new_elem->content, content, content_size);
		new_elem->content_size = content_size;
	}
	else
	{
		new_elem->content = NULL;
		new_elem->content_size = 0;
	}
	return (0);
}
