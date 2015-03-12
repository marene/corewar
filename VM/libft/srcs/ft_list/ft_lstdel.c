/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:30:54 by nperrin           #+#    #+#             */
/*   Updated: 2014/12/17 22:59:35 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cur_list;
	t_list	*prev_list;

	if (alst != NULL ? !*alst : 0)
		return ;
	cur_list = *alst;
	while ((prev_list = cur_list))
	{
		if (cur_list)
			cur_list = cur_list->next;
		if (del)
			(*del)(prev_list->content, prev_list->content_size);
		else
			free(prev_list->content);
		free(prev_list);
	}
	*alst = NULL;
}
