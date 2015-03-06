/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 09:49:02 by marene            #+#    #+#             */
/*   Updated: 2013/11/27 17:19:16 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)s1)[i] = ((unsigned char*)s2)[i];
		if (((unsigned char*)s2)[i] == (unsigned char)c)
			return (&((unsigned char*)s1)[++i]);
		i++;
	}
	return (NULL);
}
