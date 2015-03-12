/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:23:32 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/03 12:23:36 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int tmp;

	if (n < 0)
	{
		ft_putchar('-');
		tmp = -n;
	}
	else
		tmp = n;
	if (tmp >= 10)
		ft_putnbr(tmp / 10);
	ft_putchar(tmp % 10 + '0');
}
