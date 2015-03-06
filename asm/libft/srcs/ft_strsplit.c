/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:17:18 by marene            #+#    #+#             */
/*   Updated: 2015/03/05 10:37:40 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_wcount(const char *s, char c)
{
	size_t	i;
	size_t	w_nb;

	i = 0;
	w_nb = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			w_nb++;
			while (s[i] != c)
			{
				if (!s[i])
					return (w_nb);
				i++;
			}
		}
		else
			i++;
	}
	return (w_nb);
}

static int		ft_word_len(const char *s, size_t i, char c)
{
	size_t	w_len;

	w_len = 0;
	while (s[i] != c)
	{
		if (!s[i])
			return (w_len);
		i++;
		w_len++;
	}
	return (w_len);
}

static char		**ft_makearray(const char *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		index;
	char		**array;
	size_t		len;

	index = 0;
	i = 0;
	len = ft_wcount(s, c);
	array = (char**)malloc(sizeof(char*) * (len + 1));
	array[len] = NULL;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = ft_word_len(s, i, c);
			array[index] = ft_strsub(s, i, j);
			index++;
			i = i + j;
		}
		else
			i++;
	}
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;

	if (ft_strcmp(s, "") == 0 || (ft_strlen(s) == 1 && s[0] == c))
	{
		array = malloc(sizeof(char*));
		array[0] = NULL;
		return (array);
	}
	else if (ft_strlen(s) == 1 && s[0] != c)
	{
		array = malloc(sizeof(char*) * 2);
		ft_strcpy(array[0], "");
		array[1] = NULL;
	}
	array = ft_makearray(s, c);
	return (array);
}
