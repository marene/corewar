/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:11:03 by marene            #+#    #+#             */
/*   Updated: 2014/01/11 16:14:08 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
void	*ft_memalloc(size_t size)
{
	long	*ptr;
	size_t	i;

	if (size == 0)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = '\0';
		i++;
	}
	return ((void*)ptr);
}
