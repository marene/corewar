/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:40:21 by marene            #+#    #+#             */
/*   Updated: 2014/04/15 12:18:58 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*ptr;

	if (s != NULL)
	{
		ptr = s;
		i = 0;
		while (i < sizeof(unsigned char) * n)
		{
			if ((unsigned char)(ptr[i]) == (unsigned char)c)
			{
				return ((void *)&(ptr[i]));
			}
			i++;
		}
	}
	return (NULL);
}
