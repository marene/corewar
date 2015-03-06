/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:57:26 by marene            #+#    #+#             */
/*   Updated: 2014/04/15 09:07:41 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	if (!b)
		return (b);
	i = 0;
	while (i < sizeof(unsigned char) * len)
	{
		((char*)b)[i] = c;
		i++;
	}
	return (b);
}
