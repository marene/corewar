/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:25:37 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/03 12:25:38 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	unsigned int	i;

	if (dst == src)
		return (dst);
	i = 0;
	while ((dst[i] = src[i]))
		i++;
	return (dst);
}
