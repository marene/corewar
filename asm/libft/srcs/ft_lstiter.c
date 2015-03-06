/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 11:18:35 by marene            #+#    #+#             */
/*   Updated: 2013/11/29 15:42:36 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** BEWARE: funtion pointed by (*f) shouldn't be modifying elem->next, as the
** behaviour would be then undefined (and kinda weird).
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*next;

	next = lst;
	while (next)
	{
		(*f)(next);
		next = next->next;
	}
}
