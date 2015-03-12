/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 10:42:58 by nperrin           #+#    #+#             */
/*   Updated: 2014/12/17 23:24:52 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_tab_del(void ***tab, int *size, void (*f)(void *))
{
	int		i;

	if (tab ? !*tab : 1)
		return ;
	i = 0;
	while (size ? (i < *size) : *(tab[i]) != NULL)
	{
		if (*tab[i])
		{
			if (f)
				(*f)(*(tab[i]));
			else
				free(*(tab[i]));
		}
		i++;
	}
	free(*tab);
	*tab = NULL;
}
