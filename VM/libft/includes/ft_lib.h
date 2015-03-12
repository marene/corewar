/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 20:08:12 by nperrin           #+#    #+#             */
/*   Updated: 2015/01/25 20:08:14 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

# include <string.h>

int			ft_atoi(const char *str);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_itoa(int n);

#endif
