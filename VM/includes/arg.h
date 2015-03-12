/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 10:32:36 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 10:32:37 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_H
# define ARG_H

unsigned			init_arg(t_process *p, t_arg_type type[], int value[]);

unsigned			load_arg(t_process *p);
t_arg_type			cget_type(int n);
int					cget_arg(int n);
void				cset_arg(int n, int value);

#endif
