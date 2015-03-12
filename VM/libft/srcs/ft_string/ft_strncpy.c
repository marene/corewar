/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:27:44 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/05 13:26:48 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	if (n == 0)
		return (dst);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		if (!dst[i])
			break ;
		i++;
	}
	while (i < n)
		dst[i++] = '\0';
	return (dst);
}
