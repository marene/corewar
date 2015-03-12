/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:18:10 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/03 12:18:13 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*s;
	static char	str[12];
	static int	i;
	static int	j;
	static int	is_negatif;

	if (!j++)
	{
		*str = '-';
		if (!(is_negatif = (n < 0)))
			n = -n;
	}
	if (n > -10)
		i = 0;
	else
	{
		ft_itoa(n / 10);
		i++;
	}
	str[i + is_negatif] = (unsigned int)-n % 10 + '0';
	j--;
	if (j == 0)
		return (s = ft_strndup(str, i + is_negatif + 1), s ? s
		: (FT_ERRNO = FT_ENOMEM, NULL));
	return (NULL);
}
