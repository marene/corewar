/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:18:51 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/03 12:18:53 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	if (alst && *alst)
	{
		next = (*alst)->next;
		if (del)
			(*del)((*alst)->content, (*alst)->content_size);
		else if ((*alst)->content)
			free((*alst)->content);
		free(*alst);
		*alst = next;
	}
}
