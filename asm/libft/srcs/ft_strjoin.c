/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 16:46:43 by marene            #+#    #+#             */
/*   Updated: 2014/04/22 20:20:15 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_make_str(size_t len1, size_t len2, char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = ft_strnew(len1 + len2 + 1);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len2 + len1)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return (str);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	if (s2)
		len2 = ft_strlen(s2);
	else
		len2 = 0;
	str = ft_make_str(len1, len2, (char*)s1, (char*)s2);
	return (str);
}
