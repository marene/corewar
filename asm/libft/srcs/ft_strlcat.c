/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 12:20:20 by marene            #+#    #+#             */
/*   Updated: 2014/04/15 12:20:24 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = 0;
	srclen = 0;
	if (!size)
		return (ft_strlen(src));
	while (dst[dstlen] && dstlen < size)
		dstlen++;
	while (srclen + dstlen + 1 < size && src[srclen])
	{
		if (srclen + dstlen < size)
			dst[dstlen + srclen] = src[srclen];
		srclen++;
	}
	if (srclen + dstlen < size)
		dst[dstlen + srclen] = '\0';
	if (size < dstlen)
		return (size + srclen);
	return (ft_strlen(src) + dstlen);
}
