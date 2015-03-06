/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 10:43:15 by marene            #+#    #+#             */
/*   Updated: 2013/11/29 15:41:12 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	if (*alst)
	{
		next = *alst;
		while (next)
		{
			(*del)(next->content, next->content_size);
			next = next->next;
		}
		free(*alst);
	}
}
