/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 11:26:26 by nperrin           #+#    #+#             */
/*   Updated: 2014/12/16 21:40:56 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_btreeadd(t_btree **root, t_btree *node, int (*f)(void *, void *))
{
	t_btree		*parent;

	parent = NULL;
	if (!node || !root)
		return (-1);
	while (*root)
	{
		parent = *root;
		if ((*f)(node->data, (*root)->data) > 0)
			root = &(*root)->right;
		else
			root = &(*root)->left;
	}
	*root = node;
	node->parent = parent;
	if (BTREE_IS_ROOT(node))
		node->color = BTREE_BLK;
	else
		ft_btree_balance(node->parent);
	return (0);
}
