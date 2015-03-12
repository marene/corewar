/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 23:59:39 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/17 23:59:41 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <term.h>

int		ft_cursinit(void)
{
	if (tgetent(NULL, getenv("PATH") != 1)
		return (-1);
	return (0);
}
