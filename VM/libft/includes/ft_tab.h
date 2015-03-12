/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/25 20:09:22 by nperrin           #+#    #+#             */
/*   Updated: 2015/01/25 20:09:25 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAB_H
# define FT_TAB_H

int			ft_sort_tab(void **tab, size_t size, int (*f)(void *, void *));
int			ft_tablen(void **tab);
void		ft_tab_del(void ***tab, int *size, void (*f)(void *));

#endif
