/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:27:51 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/03 15:27:55 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	if (i >= size)
		return (size + ft_strlen(src));
	j = 0;
	while (((i + j) < (size - 1)) && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[j + i] = '\0';
	return (i + ft_strlen(src));
}
