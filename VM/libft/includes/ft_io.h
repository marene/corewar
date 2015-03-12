/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 20:06:18 by nperrin           #+#    #+#             */
/*   Updated: 2015/01/25 20:06:24 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <string.h>

void		ft_putchar(char c);
size_t		ft_putstr(char const *s);
void		ft_putendl(char const *s);
void		ft_putnbr(int n);

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);

#endif
