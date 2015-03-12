/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:28:48 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/03 12:28:50 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (s1[i])
	{
		if (s1[i] == *s2)
		{
			j = 0;
			while (s1[i + j] == s2[j])
				if (!s2[++j])
					return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
