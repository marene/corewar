/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/15 13:39:46 by marene            #+#    #+#             */
/*   Updated: 2014/05/16 18:19:53 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_isnumber(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((i > 0 && (str[i] == '-' || str[i] == '+')) || (str[i] >= '0'
					|| str[i] <= '9'))
			i++;
		else
			return (0);
	}
	if ((str[0] == '-' && ft_strcmp(str, STR_MIN_INT) < 0) || (str[0] != '-'
				&& ft_strcmp(str, STR_MAX_INT) < 0))
		return (0);
	return (1);
}
