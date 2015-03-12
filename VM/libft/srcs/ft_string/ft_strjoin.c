/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:26:53 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/03 12:26:54 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;

	if (!(new_str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1))))
	{
		FT_ERRNO = FT_ENOMEM;
		return (NULL);
	}
	ft_strcpy(new_str, s1);
	ft_strcat(new_str, s2);
	return (new_str);
}
