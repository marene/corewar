/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 07:18:48 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 07:18:51 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	load_prog(int fd, int champ_size, const char *path)
{
	int			ret;
	t_champ		*champ;

	if (!(champ = ft_memalloc(sizeof(t_champ))))
	{
		perror("corewar");
		exit(1);
	}
	if ((ret = read(fd, champ, champ_size)) != champ_size)
	{
		if (ret == -1)
			perror("corewar");
		else
			ft_putstr_fd("corewar: invalide header.", 2);
		ft_putstr_fd("file: ", 2), ft_putendl_fd(path, 2);
		exit(1);
	}
	add_champ(champ);
}
