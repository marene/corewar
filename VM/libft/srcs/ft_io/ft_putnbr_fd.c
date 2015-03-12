/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:23:43 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/03 12:24:14 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int tmp;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		tmp = -n;
	}
	else
		tmp = n;
	if (tmp >= 10)
		ft_putnbr_fd(tmp / 10, fd);
	ft_putchar_fd(tmp % 10 + '0', fd);
}
