/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 16:06:48 by marene            #+#    #+#             */
/*   Updated: 2013/12/22 21:10:05 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(const char *str, int fd)
{
	size_t	len;

	len = ft_strlen(str) + 1;
	write(fd, str, len);
	write(fd, "\n", 1);
}
