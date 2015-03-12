/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreenew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 11:21:41 by nperrin           #+#    #+#             */
/*   Updated: 2014/12/16 21:40:58 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_btree		*ft_btreenew(void *data)
{
	t_btree		*node;

	if (!(node = (t_btree *)malloc(sizeof(t_btree))))
		return (NULL);
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	node->color = BTREE_RED;
	return (node);
}
