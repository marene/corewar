/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_suffix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 11:37:12 by nperrin           #+#    #+#             */
/*   Updated: 2014/12/16 12:00:14 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_suffix(t_btree *root, void (*f)(t_btree *node))
{
	if (!root)
		return ;
	if (root->left)
		ft_btree_suffix(root->left, f);
	if (root->right)
		ft_btree_suffix(root->right, f);
	(*f)(root);
}
