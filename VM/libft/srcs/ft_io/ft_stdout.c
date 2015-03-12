/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdout.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 14:44:17 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/18 15:15:58 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

t_file		*ft_stdout(void)
{
	static char		buf[FT_STDOUT_BUF_SIZE];
	static t_file	ft_stdout_stream =

	{1, buf, buf, buf + FT_STDOUT_BUF_SIZE - 1};
	return (&ft_stdout_stream);
}

uint16_t	ft_flush_stdout(void)
{
	t_file		*stream;
	uint16_t	tmp;

	stream = FT_STDOUT;
	tmp = stream->ptr - stream->buf;
	stream->ptr = stream->buf;
	write(1, stream->buf, tmp);
	stream->ptr = stream->buf;
	return (tmp);
}
