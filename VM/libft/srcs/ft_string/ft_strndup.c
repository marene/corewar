/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:57:01 by nperrin           #+#    #+#             */
/*   Updated: 2014/12/16 21:35:48 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*cpy;
	size_t	size;

	if ((size = ft_strlen(s)) > n)
		size = n;
	if (!(cpy = (char *)malloc(sizeof(char) * (size + 1))))
	{
		FT_ERRNO = FT_ENOMEM;
		return (NULL);
	}
	cpy[size] = '\0';
	return (ft_strncpy(cpy, s, size));
}
