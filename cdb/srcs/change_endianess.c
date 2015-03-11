/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_endianess.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 12:12:26 by marene            #+#    #+#             */
/*   Updated: 2015/03/11 14:02:57 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		swap(unsigned int val)
{
	unsigned int	a0;
	unsigned int	a1;

	a0 = (val & 0x000000ff) << 8;
	a1 = (val & 0x0000ff00) >> 8;
	return (a0 | a1);
}

unsigned int		change_endianess(unsigned int val)
{
	unsigned int	a0;
	unsigned int	a1;
	unsigned int	a2;
	unsigned int	a3;

	a0 = (val & 0x000000ff) << 24;
	a1 = (val & 0x0000ff00) << 8;
	a2 = (val & 0x00ff0000) >> 8;
	a3 = (val & 0xff000000) >> 24;
	return (a0 | a1 | a2 | a3);
}
