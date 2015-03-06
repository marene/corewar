/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:42:23 by marene            #+#    #+#             */
/*   Updated: 2013/11/27 11:50:01 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	len;
	char	*new_str;

	len = ft_strlen(s);
	new_str = ft_strnew(len + 1);
	i = 0;
	while (i < len)
	{
		new_str[i] = (*f)(s[i]);
		i++;
	}
	return (new_str);
}
