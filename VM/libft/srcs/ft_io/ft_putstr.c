/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:24:36 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/18 18:13:12 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_putstr(char const *s)
{
	t_file	*stream;
	size_t	i;

	if (!s)
		return (ft_putstr("(null)"));
	stream = FT_STDOUT;
	i = 0;
	while (s[i])
	{
		*stream->ptr = s[i];
		stream->ptr++;
		i++;
		if (stream->ptr == stream->end)
			ft_flush_stdout();
	}
	return (i);
}
