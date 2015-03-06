/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 16:06:48 by marene            #+#    #+#             */
/*   Updated: 2013/11/27 11:54:07 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl(const char *str)
{
	size_t	len;

	len = ft_strlen(str) + 1;
	write(1, str, len);
	write(1, "\n", 1);
}
