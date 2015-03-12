/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_balance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 13:07:29 by nperrin           #+#    #+#             */
/*   Updated: 2014/12/16 21:39:59 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void		swap_node(t_btree *n1, t_btree *n2)
{
	void	*tmp_p;

	tmp_p = n1->data;
	n1->data = n2->data;
	n2->data = tmp_p;
	n1->color ^= n2->color;
	n2->color ^= n1->color;
	n1->color ^= n2->color;
}

static void		rotate_left(t_btree *node)
{
	t_btree		*son;
	t_btree		*a;
	t_btree		*b;
	t_btree		*c;

	son = node->right;
	a = node->left;
	b = son->left;
	c = son->right;
	swap_node(node, son);
	node->left = son;
	son->left = a;
	if (a)
		a->parent = son;
	son->right = b;
	if (b)
		b->parent = son;
	node->right = c;
	if (c)
		c->parent = node;
}

static void		rotate_right(t_btree *node)
{
	t_btree		*son;
	t_btree		*a;
	t_btree		*b;
	t_btree		*c;

	son = node->left;
	a = son->left;
	b = son->right;
	c = node->right;
	swap_node(node, son);
	node->right = son;
	node->left = a;
	if (a)
		a->parent = node;
	son->left = b;
	if (b)
		b->parent = son;
	son->right = c;
	if (c)
		c->parent = son;
}

void			ft_btree_balance(t_btree *node)
{
	if (BTREE_IS_BLK(node))
		return ;
	if (BTREE_IS_RED(BTREE_BROS(node)))
	{
		BTREE_BROS(node)->color = BTREE_BLK;
		node->color = BTREE_BLK;
		node->parent->color = BTREE_IS_ROOT(node->parent) ? 1 : 0;
		if (!BTREE_IS_ROOT(node->parent))
			ft_btree_balance(node->parent->parent);
		return ;
	}
	else if (BTREE_IS_LEFT(node))
	{
		if (BTREE_IS_RED(node->right))
			rotate_left(node);
		node->parent->color = BTREE_RED;
		node->color = BTREE_BLK;
		rotate_right(node->parent);
		return ;
	}
	if (BTREE_IS_RED(node->left))
		rotate_right(node);
	node->parent->color = BTREE_RED;
	node->color = BTREE_BLK;
	rotate_left(node->parent);
}
