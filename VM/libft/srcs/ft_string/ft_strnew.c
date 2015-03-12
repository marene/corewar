/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:28:23 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/03 12:28:24 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_errno.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)malloc(size + 1)))
	{
		FT_ERRNO = FT_ENOMEM;
		return (NULL);
	}
	i = 0;
	while (i <= size)
		str[i++] = '\0';
	return (str);
}
