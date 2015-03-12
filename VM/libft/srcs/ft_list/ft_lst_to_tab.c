/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 10:33:06 by nperrin           #+#    #+#             */
/*   Updated: 2014/12/16 21:38:08 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	**ft_lst_to_tab(t_list *lst, int *size)
{
	int		len;
	int		i;
	void	**tab;

	len = ft_lst_len(lst);
	if (len == 0 && !size)
		return (NULL);
	if (!(tab = (void **)malloc(sizeof(void *) * (size ? len : len + 1))))
	{
		FT_ERRNO = FT_ENOMEM;
		return (0);
	}
	if (size)
		*size = len;
	else
		tab[len] = NULL;
	i = 0;
	while (i < len)
	{
		tab[i] = lst->content;
		i++;
		lst = lst->next;
	}
	return (tab);
}
