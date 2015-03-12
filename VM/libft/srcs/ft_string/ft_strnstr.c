/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:33:33 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/03 15:33:35 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	j;
	size_t	i;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		if (s1[i] == *s2)
		{
			j = 0;
			while ((s1[i + j] == s2[j]) && ((i + j) < n))
				if (!s2[++j])
					return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
