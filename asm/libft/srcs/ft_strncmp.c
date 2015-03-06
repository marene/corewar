/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:08:12 by marene            #+#    #+#             */
/*   Updated: 2013/12/22 21:15:14 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	result;

	i = 0;
	while (s1[i] && s2[i] &&
			(unsigned char)s1[i] == (unsigned char)s2[i] && (size_t)i < n)
		i++;
	result = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (result);
}
