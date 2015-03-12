/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 19:37:49 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/08 19:37:50 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_perror(const char *s)
{
	if (FT_ERRNO > 0 && FT_ERRNO < FT_ELAST)
	{
		ft_putstr_fd(s, 2);
		ft_putstr_fd(strerror(FT_ERRNO), 2);
	}
}
