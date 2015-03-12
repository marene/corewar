/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 11:14:50 by nperrin           #+#    #+#             */
/*   Updated: 2014/12/16 21:39:20 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H

# define BTREE_BLK 1
# define BTREE_RED 0
# define BTREE_IS_BLK(X) (X ? (X->color == BTREE_BLK) : 1)
# define BTREE_IS_RED(X) (X ? (X->color == BTREE_RED) : 0)
# define BTREE_IS_ROOT(X) (X->parent ? 0 : 1)
# define BTREE_IS_LEFT(X) (X->parent->left == X ? 1 : 0)
# define BTREE_IS_RIGHT(X) (X->parent->right == X ? 1 : 0)
# define BTREE_BROS(X) (BTREE_IS_RIGHT(X) ? X->parent->left : X->parent->right)

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	struct s_btree	*parent;
	void			*data;
	char			color;
}					t_btree;

t_btree				*ft_btreenew(void *data);
int					ft_btreeadd(t_btree **root, t_btree *node
												, int (*f)(void *, void *));
void				ft_btree_prefix(t_btree *root, void (*f)(t_btree *node));
void				ft_btree_infix(t_btree *root, void (*f)(t_btree *node));
void				ft_btree_suffix(t_btree *root, void (*f)(t_btree *node));
void				ft_btree_balance(t_btree *node);

#endif
