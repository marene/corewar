/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:20:33 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/03 12:20:39 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_errno.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;
	size_t	i;

	if (size == 0)
		return (NULL);
	if (!(ptr = malloc(size)))
		return (FT_ERRNO = FT_ENOMEM, NULL);
	i = 0;
	while (i < size)
		((char *)ptr)[i++] = 0;
	return (ptr);
}
