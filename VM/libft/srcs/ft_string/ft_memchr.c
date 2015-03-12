/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:21:14 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/05 13:32:03 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*p;

	ch = c;
	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (p[i] == ch)
			return (p + i);
		i++;
	}
	return (NULL);
}
