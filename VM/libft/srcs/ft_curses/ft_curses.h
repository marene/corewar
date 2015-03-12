/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curses.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 00:05:00 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/18 00:05:01 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CURSES_H
# define FT_CURSES_H

# include "libft.h"

typedef struct	s_cpix
{
	unsigned	c : 8;
	unsigned	color : 4;
	unsigned	is_video : 1;
	unsigned	is_under : 1;
}				t_cpix;

typedef struct	s_cimg
{
	int			h;
	int			w;
	t_cpix		**pix;
}				t_cimg;

#endif
