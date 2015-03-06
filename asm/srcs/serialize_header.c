/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 12:19:18 by marene            #+#    #+#             */
/*   Updated: 2015/02/20 14:43:33 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <op.h>

void				*serialize_header(t_header *head)
{
	char		*ret;
	int			i;
	int			shift;
	char		mask;

	mask = 0xff;
	shift = 0;
	len = sizeof(t_header);
	ret = malloc(len);
	--len;
	while (len >= 0)
	{
		ret[len] = (*head & mask) >> shift;
		--len;
		mask << 8;
		shift += 8;
	}
	return ((void *)ret);
}
