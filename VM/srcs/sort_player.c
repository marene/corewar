/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 15:13:43 by marene            #+#    #+#             */
/*   Updated: 2015/03/12 15:24:40 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	sort_player(char **path, int *pos, int *take, int n)
{
	int i;
	int j;

	i = -1;
	while (++i < n)
	{
		if (pos[i] == -1)
		{
			j = 0;
			while (take[j])
				j++;
			pos[i] = j + 1;
			take[j] = 1;
		}
	}
	i = 0;
	while (i < n - 1)
		if (pos[i] > pos[i + 1])
		{
			FT_SWAP(pos[i], pos[i + 1]);
			FT_SWAP_PTR(path[i], path[i + 1]);
			i = 0;
		}
		else
			i++;
}
