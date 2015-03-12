/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_infix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 11:38:19 by nperrin           #+#    #+#             */
/*   Updated: 2014/12/16 12:00:22 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_infix(t_btree *root, void (*f)(t_btree *node))
{
	if (!root)
		return ;
	if (root->left)
		ft_btree_infix(root->left, f);
	(*f)(root);
	if (root->right)
		ft_btree_infix(root->right, f);
}
