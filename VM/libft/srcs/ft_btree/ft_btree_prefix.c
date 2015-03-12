/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 11:33:35 by nperrin           #+#    #+#             */
/*   Updated: 2014/12/16 11:57:29 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_prefix(t_btree *root, void (*f)(t_btree *node))
{
	if (!root)
		return ;
	(*f)(root);
	if (root->left)
		ft_btree_prefix(root->left, f);
	if (root->right)
		ft_btree_prefix(root->right, f);
}
