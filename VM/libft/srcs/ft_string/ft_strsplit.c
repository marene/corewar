/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:28:40 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/09 18:41:35 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_strsplit(char const *s, char c)
{
	char					**tab_s;
	unsigned int			len;
	static unsigned int		i;

	i++;
	while (*s == c)
		s++;
	if (!*s)
	{
		if (!(tab_s = (char **)malloc(sizeof(char *) * i)))
			return (FT_ERRNO = FT_ENOMEM, NULL);
		tab_s[--i] = NULL;
		return (tab_s);
	}
	len = 0;
	while (s[len] != c && s[len])
		len++;
	if (!(tab_s = ft_strsplit(s + len, c)))
		return (NULL);
	if ((tab_s[--i] = (char *)malloc(sizeof(char) * (len + 1))))
	{
		ft_strncpy(tab_s[i], s, len);
		tab_s[i][len] = '\0';
	}
	return (tab_s);
}
