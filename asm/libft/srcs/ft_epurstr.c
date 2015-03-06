/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_epurstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 19:01:52 by marene            #+#    #+#             */
/*   Updated: 2014/05/17 19:29:20 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** INFO: w_nb is the inputed string's words number, while c_nb is the number of
** non white characters contained in the inputed string.
*/

static char		*epur(char *str, int len)
{
	char	*epur;
	char	prev;
	int		i;
	int		j;

	i = 0;
	j = 0;
	epur = (char*)malloc(sizeof(char) * (len + 1));
	epur[len] = '\0';
	while (i < len && str[j])
	{
		if (!ft_iswhite(str[j]))
		{
			epur[i] = str[j];
			i++;
		}
		if (!ft_iswhite(prev) && ft_iswhite(str[j]))
		{
			epur[i] = ' ';
			i++;
		}
		prev = str[j];
		j++;
	}
	return (epur);
}

char			*ft_epurstr(char *str)
{
	int		w_nb;
	int		c_nb;
	int		i;
	char	prev;

	i = 0;
	w_nb = 0;
	c_nb = 0;
	prev = ' ';
	if (str)
	{
		while (str[i])
		{
			if (!ft_iswhite(str[i]))
			{
				if (ft_iswhite(prev))
					w_nb++;
				c_nb++;
			}
			prev = str[i];
			i++;
		}
		return (epur(str, c_nb + w_nb - 1));
	}
	return (NULL);
}
