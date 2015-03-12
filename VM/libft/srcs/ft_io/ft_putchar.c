/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:22:31 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/18 15:13:12 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	t_file	*stream;

	stream = FT_STDOUT;
	*(stream->ptr++) = c;
	if (stream->ptr >= stream->end)
		ft_flush_stdout();
}
