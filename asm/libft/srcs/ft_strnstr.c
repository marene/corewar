/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:30:57 by marene            #+#    #+#             */
/*   Updated: 2013/12/22 21:15:44 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (!s2 || !s2[0])
		return ((char*)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		if (s1[i] == s2[j])
			while (s1[i + j] && s1[i + j] == s2[j] && i + j < n)
				if (!s2[++j])
					return ((char*)&s1[i]);
		i++;
	}
	return (NULL);
}
