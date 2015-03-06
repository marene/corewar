/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:51:29 by marene            #+#    #+#             */
/*   Updated: 2013/11/27 17:20:12 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t					i;
	unsigned char			*ptr1;
	const unsigned char		*ptr2;

	if (s1 < s2)
		return (ft_memcpy(s1, s2, n));
	else if (s1 == s2)
		return (s1);
	i = n - 1;
	ptr1 = s1;
	ptr2 = s2;
	while ((int)i >= 0)
	{
		ptr1[i] = ptr2[i];
		i--;
	}
	return (s1);
}
