/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 10:01:29 by marene            #+#    #+#             */
/*   Updated: 2015/03/12 09:04:34 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (*alst)
	{
		if ((*alst)->content)
			(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
	}
	alst = NULL;
}
