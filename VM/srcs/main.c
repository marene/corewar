/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 10:33:54 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/12 13:00:38 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		init_game(int argc, char **argv)
{
	char	**path;

	load_flag(&argc, &argv);
	path = load_path(argv);
	init_arena();
	while (*path)
		load_champ(*path++);
	init_data();
	write_prog();
}

static void		apply_process(void)
{
	t_list	*lst;

	lst = *get_process_lst();
	while (lst)
	{
		exec_process(lst->content);
		lst = lst->next;
	}

}

static void		game(void)
{
	while (N_PROC)
	{
		apply_process();
		check();
	}
	ft_flush_stdout();
}

t_player	*get_winner(void)
{
	unsigned	i;
	t_player	*best;

	best = get_player(1);
	i = 2;
	printf("j%d, %u\n", 1, get_player(1)->last_live);
	while (i <= N_PLAYER)
	{
		printf("j%d, %u\n", i, get_player(i)->last_live);
		if (get_player(i)->last_live > best->last_live)
			best = get_player(i);
		i++;
	}
	if (best->last_live == 0)
		return (NULL);
	else
		return (best);
}

int		main(int argc, char **argv)
{
	t_player	*winner;

	init_game(argc - 1, argv + 1);
	game();
	winner = get_winner();
	if (!winner)
		ft_putstr("Egalite\n");
	else
	{
		ft_putstr("le joueur "), ft_putchar(winner->id + '0');
		ft_putchar('('), ft_putstr(winner->header.prog_name);
		ft_putchar(')');
		ft_putstr(" a gagne\n");
	}
	ft_flush_stdout();
	return (0);
}
