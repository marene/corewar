/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 18:32:52 by marene            #+#    #+#             */
/*   Updated: 2015/02/25 15:07:34 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static size_t	ft_sizealloc(int n, int *pow)
{
	size_t	i;

	*pow = 1;
	i = 1;
	while (ft_abs(n / *pow) >= 10)
	{
		*pow *= 10;
		i++;
	}
	i++;
	if (n < 0)
		i++;
	return (i);
}

static char		*ft_makestr(char *str, int n, int pow, size_t len)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		str[0] = '-';
		i++;
	}
	n = ft_abs(n);
	while (i < len)
	{
		str[i] = n / pow + '0';
		n = n - (n / pow * pow);
		pow /= 10;
		i++;
	}
	str[len] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	int		pow;
	size_t	len;
	char	*str;

	if (n == MIN_INT)
		return (ft_strsub("-2147483648", 0, 11));
	len = ft_sizealloc(n, &pow);
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	if (!str)
		return (NULL);
	len--;
	return (ft_makestr(str, n, pow, len));
}
