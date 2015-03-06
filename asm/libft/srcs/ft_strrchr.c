/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:15:10 by marene            #+#    #+#             */
/*   Updated: 2013/12/06 19:03:52 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strrchr(const char *s, char c)
{
	int	len;
	int	i;

	len = ft_strlen(s);
	if (c == '\0')
		return ((char*)&s[len]);
	i = len;
	while (i >= 0 && s[i] != c)
		i--;
	if (s[i] == c)
		return ((char*)&s[i]);
	else
		return (NULL);
}
