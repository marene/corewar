/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:25:53 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/03 12:25:54 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*cpy;

	if (!(cpy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
	{
		FT_ERRNO = FT_ENOMEM;
		return (NULL);
	}
	return (ft_strcpy(cpy, s1));
}
