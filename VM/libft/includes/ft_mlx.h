/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 15:18:45 by nperrin           #+#    #+#             */
/*   Updated: 2015/02/08 15:18:46 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# ifndef NO_GLOBAL

void	*g_mlx_ptr;

# endif
# ifdef NO_GLOBAL

void	**mlx_ptr_singelton__(void);

# endif

#endif
