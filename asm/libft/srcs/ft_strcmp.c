/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:08:12 by marene            #+#    #+#             */
/*   Updated: 2013/11/27 17:27:08 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	result;

	i = 0;
	while (s1[i] && s2[i] &&
			(unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	result = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (result);
}
