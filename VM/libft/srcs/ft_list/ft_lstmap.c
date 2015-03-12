/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:20:10 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/11 19:46:21 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*cur_list;

	if (!lst)
		return (NULL);
	if (!(new_list = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	new_list = (*f)(new_list);
	cur_list = new_list;
	while ((lst = lst->next))
	{
		if (!(cur_list->next = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		cur_list = cur_list->next;
		cur_list = (*f)(cur_list);
	}
	return (new_list);
}
