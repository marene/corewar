/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:21:49 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/03 12:21:54 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;
	size_t	i;

	if ((len == 0) || (dst == src))
		return (dst);
	if (!(tmp = (char *)malloc (sizeof(char) * len)))
		return (dst);
	i = 0;
	while (i < len)
	{
		tmp[i] = ((char *)src)[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		((char *)dst)[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (dst);
}
