/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:27:11 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/03 12:27:15 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	if (!(new_str = (char *)malloc(sizeof(char) * (s_len + 1))))
	{
		FT_ERRNO = FT_ENOMEM;
		return (NULL);
	}
	i = 0;
	while (i < s_len)
	{
		new_str[i] = (*f)(s[i]);
		i++;
	}
	new_str[s_len] = '\0';
	return (new_str);
}
