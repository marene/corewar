/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 11:02:21 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/12 16:03:09 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	check_path(char *path)
{
	char	*p;

	if (!path)
		CEXIT("expected path after [-n value]");
	if (!(p = ft_strrchr(path, '.')))
	{
		ft_putstr_fd("corewar: invalide file name.\n", 2);
		ft_putstr_fd("file: ", 2), ft_putendl_fd(path, 2);
		exit(1);
	}
	if ((ft_strcmp(p, ".cor")))
	{
		ft_putstr_fd("corewar: invalide file name.\n", 2);
		ft_putstr_fd("file: ", 2), ft_putendl_fd(path, 2);
		exit(1);
	}
}

void	ft_swap_ptr(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		check_value(char *str)
{
	if (!str)
		CEXIT("expected valuer after -n.");
	while (*str)
		if (ft_isdigit(*str))
			str++;
		else
			CEXIT("invalide value after -n.");
	return (1);
}

void	check_player_id(int *pos, int n)
{
	int i;
	int j;

	i = 0;
	while (i < n)
		if (pos[i++] > n)
			CEXIT("invalide player id.");
	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if ((pos[i] != -1) && (pos[i] == pos[j]))
				CEXIT("invalide player id.");
			j++;
		}
		i++;
	}
}

char	**load_path(char **argv)
{
	unsigned		i;
	static char		*path[MAX_PLAYERS];
	int				t_p[2][MAX_PLAYERS];

	i = 0;
	ft_bzero(t_p[0], sizeof(int) * MAX_PLAYERS);
	while (*argv)
	{
		if (i >= MAX_PLAYERS)
			CEXIT("too many arguments.");
		if (!ft_strcmp(*argv, "-n") && check_value(*(++argv)))
		{
			if ((t_p[1][i] = ft_atoi(*argv)) <= 0 || t_p[1][i] > MAX_PLAYERS)
				CEXIT("invalide value after -n.");
			argv++;
			t_p[0][t_p[1][i] - 1] = 1;
		}
		else
			t_p[1][i] = -1;
		path[i] = *argv++;
		check_path(path[i++]);
	}
	check_player_id(t_p[1], i);
	sort_player((char **)path, t_p[1], t_p[0], i);
	return ((char **)path);
}
