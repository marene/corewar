/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 10:17:13 by marene            #+#    #+#             */
/*   Updated: 2014/02/26 13:24:46 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	start;
	size_t	end;
	char	*str;

	len = ft_strlen(s);
	start = 0;
	end = len - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	str = ft_strsub(s, start, end - start + 1);
	str[end - start + 1] = '\0';
	return (str);
}
