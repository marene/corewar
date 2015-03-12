/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:27:29 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/03 12:27:30 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	s1_len;

	if (n == 0)
		return (s1);
	i = 0;
	s1_len = ft_strlen(s1);
	while (s2[i] && (i < n))
	{
		s1[s1_len + i] = s2[i];
		i++;
	}
	s1[i + s1_len] = '\0';
	return (s1);
}
