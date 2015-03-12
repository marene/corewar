/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:29:11 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/03 12:29:12 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_errno.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	i;

	if (!(new_str = (char *)malloc(len + 1)))
	{
		FT_ERRNO = FT_ENOMEM;
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[len] = '\0';
	return (new_str);
}
