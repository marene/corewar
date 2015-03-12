/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 05:56:11 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 05:56:13 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAMPION_H
# define CHAMPION_H

# include "corewar.h"

typedef t_byte	t_champ[CHAMP_MAX_SIZE];

void			load_champ(const char *path);
void			add_champ(t_champ *champ);
void			load_prog(int fd, int champ_size, const char *path);
void			write_prog(void);
void			cp_champion(t_champ *champ, long pos, unsigned c);

#endif
