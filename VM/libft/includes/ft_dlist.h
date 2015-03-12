/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 20:17:58 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/07 20:17:59 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_H
# define FT_DLIST_H

# include <string.h>

# define COPY_DATA
# define ALLOC_DATA
# define DLST_GO_NEXT(X) ((X) = (X)->next)
# define DLST_GO_PREV(X) ((X) = (X)->prev)

typedef struct s_dlist_index	t_idlist;

typedef struct				s_dlist
{
	struct s_dlist			*prev;
	struct s_dlist			*next;
	t_idlist				*mother;
	void					*data;
	size_t					size;
}							t_dlist;

typedef struct				s_dlist_index
{
	t_dlist					*first;
	t_dlist					*last;
	void 					(*del_fct)(void *, size_t);
	size_t					len;
}							t_idlist;

#endif
