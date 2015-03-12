/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 10:34:41 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 10:34:42 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		check_dump(char *str)
{
	while (*str)
		if (ft_isdigit(*str))
			str++;
		else
			CEXIT("invalide value after -dump.");
}

void	load_flag(int *argc, char ***argv)
{
	if (*argc >= 1)
	{
		if (!(ft_strcmp(**argv, "-N")))
		{
			(*argc)--;
			(*argv)++;
			SET_VIDEO;
		}
		else if (!(ft_strcmp(**argv, "-dump")))
		{
			(*argc)--;
			(*argv)++;
			SET_DUMP;
			if ((*argc) >= 1)
			{
				check_dump(**argv);
				if ((g_dump_value = ft_atoi(**argv)) < 0)
					CEXIT("invalide value after -dump.");
				(*argc)--;
				(*argv)++;
			}
			else
				CEXIT("expected value after -dump.");
		}
	}
}
