/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 09:25:14 by marene            #+#    #+#             */
/*   Updated: 2014/04/15 12:18:40 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_new_elem(char *str)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	if (str == NULL)
		return (NULL);
	new->value = ft_strdup(str);
	new->next = NULL;
	return (new);
}

int		ft_list_add(t_list **root, t_list *new)
{
	if (new == NULL)
		return (0);
	if (*root == NULL)
	{
		*root = new;
		return (1);
	}
	new->next = *root;
	*root = new;
	return (1);
}
