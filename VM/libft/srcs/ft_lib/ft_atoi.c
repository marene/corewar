/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:14:38 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/03 12:14:46 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	unsigned int	nb;
	int				is_positif;

	is_positif = 1;
	nb = 0;
	while (*str == '\t' || *str == '\f' || *str == '\v'
		|| *str == '\n' || *str == ' ' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
		is_positif = (*str++ == '+');
	while (*str >= '0' && *str <= '9')
		nb = nb * 10 + *str++ - '0';
	return (is_positif ? nb : -nb);
}
