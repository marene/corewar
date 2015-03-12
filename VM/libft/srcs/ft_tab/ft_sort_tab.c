/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 02:48:22 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/29 04:53:05 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_sort__(void **tab, void **cp, size_t size
	, int (*f)(void *, void *))
{
	size_t		mid;
	size_t		i;
	size_t		j;
	size_t		k;

	mid = size / 2;
	if (mid >= 2)
		ft_sort__(tab, cp, mid, f);
	if ((size - mid) >= 2)
		ft_sort__(tab + mid, cp, (size - mid), f);
	ft_memcpy(cp, tab, size * sizeof(void *));
	i = 0;
	j = mid;
	k = 0;
	while (i < mid && j < size)
		tab[k++] = (*f)(cp[i], cp[j]) < 0 ? cp[i++] : cp[j++];
	while (i < mid)
		tab[k++] = cp[i++];
	while (j < size)
		tab[k++] = cp[j++];
}

int				ft_sort_tab(void **tab, size_t size, int (*f)(void *, void *))
{
	void	**cp;

	if (size <= 1)
		return (1);
	if (!(tab))
		return (0);
	if (!(cp = malloc(sizeof(void *) * size)))
		return (-1);
	ft_sort__(tab, cp, size, f);
	free(cp);
	return (1);
}
