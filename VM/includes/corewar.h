/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 04:49:56 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/12 16:03:57 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "op.h"
# include "libft.h"
# include "cor_var.h"
# include "player.h"
# include "arena.h"
# include "process.h"
# include "champion.h"
# include "cop.h"
# include "arg.h"

# define USG "usage: "
# define USAGE USG "./corewar [-dump nbr_cycles] [[-n number] champion1.cor]\n"

# define CVIDEO 1
# define CDUMP 2

# define SET_VIDEO (CFLAG |= CVIDEO)
# define SET_DUMP (CFLAG |= CDUMP)

# define HAS_VIDEO ((CFLAG & CVIDEO) != 0)
# define HAS_DUMP ((CFLAG & CDUMP) != 0)

# define N_PLAYER g_n_player
# define N_PROCESS g_n_proc
# define N_PROC N_PROCESS
# define CYCLE g_cycle
# define CTD g_cycle_to_die
# define CT_CYCLE g_ct_cycle
# define CFLAG g_cflag
# define N_LIVE g_n_live

# define CEXIT(S) (ft_putstr_fd("corewar: ", 2), ft_putendl_fd(S, 2), exit(1))

# define OP_OK(X) (X >= 1 && X <= 16)

extern long			g_n_player;
extern long			g_n_proc;
extern long			g_cycle;
extern long			g_cycle_to_die;
extern long			g_ct_cycle;
extern long			g_cflag;
extern long			g_dump_value;
extern long			g_n_live;

unsigned			rev_u(t_byte *n);

void				dump_mem(void);
void				load_flag(int *argc, char ***argv);
char				**load_path(char **argv);
void				init_data(void);
void				check(void);
void				sort_player(char **path, int *pos, int *take, int n);
void				ft_swap_ptr(void **a, void **b);
#endif
