/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:20:46 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/05 13:28:54 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_bis;
	unsigned char	*src_bis;

	if (n == 0)
		return (NULL);
	dst_bis = dst;
	src_bis = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_bis[i] = src_bis[i];
		if (dst_bis[i] == c)
			break ;
		i++;
	}
	if (dst_bis[i] == (unsigned char)c)
		return ((dst_bis + i + 1));
	return (NULL);
}
