/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:28:31 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/03 12:28:33 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*last_ptr;

	last_ptr = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_ptr = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (last_ptr);
}
