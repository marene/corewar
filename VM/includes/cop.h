/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cop.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 10:27:08 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 10:27:09 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COP_H
# define COP_H

# include "corewar.h"

int		clive(t_process *p);
int		cld(t_process *p);
int		cst(t_process *p);
int		cadd(t_process *p);
int		csub(t_process *p);
int		cand(t_process *p);
int		cor(t_process *p);
int		cxor(t_process *p);
int		czjmp(t_process *p);
int		cldi(t_process *p);
int		csti(t_process *p);
int		cfork(t_process *p);
int		clld(t_process *p);
int		clldi(t_process *p);
int		clfork(t_process *p);
int		caff(t_process *p);

#endif
