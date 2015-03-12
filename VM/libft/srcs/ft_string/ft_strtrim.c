/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:29:21 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/05 14:09:41 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*s2;
	unsigned int	i;
	unsigned int	j;
	unsigned int	s_size;

	i = 0;
	s_size = ft_strlen(s);
	while ((s[i] == '\t' || s[i] == '\n' || s[i] == ' ') && i < s_size)
		i++;
	if (i == s_size)
		return (ft_strdup(""));
	j = 0;
	while (s[s_size - j - 1] == '\t' || s[s_size - j - 1] == '\n'
		|| s[s_size - j - 1] == ' ')
		j++;
	if (i == 0 && j == 0)
		s2 = ft_strdup(s);
	else
		s2 = ft_strndup(s + i, s_size - i - j);
	if (!s2)
		return (FT_ERRNO = FT_ENOMEM, NULL);
	return (s2);
}
