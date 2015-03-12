/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:27:19 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/03 12:27:20 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	s_len;
	unsigned int	i;

	s_len = ft_strlen(s);
	if (!(new_str = (char *)malloc(sizeof(char) * (s_len + 1))))
	{
		FT_ERRNO = FT_ENOMEM;
		return (NULL);
	}
	i = 0;
	while (i < s_len)
	{
		new_str[i] = (*f)(i, s[i]);
		i++;
	}
	new_str[s_len] = '\0';
	return (new_str);
}
