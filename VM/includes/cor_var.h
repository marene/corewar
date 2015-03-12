/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_var.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 04:39:02 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/06 04:39:03 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COR_VAR_H
# define COR_VAR_H

# include "corewar.h"

# define VSIZE(X) (g_cvar_size[X.type])

# define VVALUE(V, X) (V.is_neg ? -(int)V.var.value[X] : (int)V.var.value[X])

# define UPPER(X, Y) ((X) > (Y) ? (X) : (Y))

extern unsigned	g_cvar_size[4];

typedef unsigned char	t_byte;

typedef t_byte	t_creg[REG_SIZE];
typedef t_byte	t_cind[IND_SIZE];
typedef t_byte	t_cdir[DIR_SIZE];

typedef union	u_nncvar
{
	t_creg		reg;
	t_cdir		dir;
	t_cind		ind;
}				t_nncvar;

typedef union	u_cvar
{
	t_byte		value[sizeof(t_nncvar)];
	t_creg		reg;
	t_cdir		dir;
	t_cind		ind;
}				t_cvar;

typedef struct	s_var
{
	t_arg_type	type;
	char		is_neg;
	t_cvar		var;
}				t_var;

#endif
