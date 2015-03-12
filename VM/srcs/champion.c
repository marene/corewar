/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 05:55:21 by nperrin           #+#    #+#             */
/*   Updated: 2015/03/03 05:55:23 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_champ				*g_champ[4];

void				add_champ(t_champ *champ)
{
	g_champ[N_PLAYER - 1] = champ;
}

static void			check_header(t_header *header, const char *path)
{
	if (rev_u((t_byte *)&header->magic) != COREWAR_EXEC_MAGIC)
	{
		ft_putstr_fd("corewar: invalide header.\n", 2);
		ft_putstr_fd("file: ", 2), ft_putendl_fd(path, 2);
		exit(1);
	}
	header->prog_size = rev_u((t_byte *)&header->prog_size);
	if (header->prog_size > CHAMP_MAX_SIZE)
	{
		ft_putstr_fd("corewar: invalide champion.\n", 2);
		ft_putstr_fd("file: ", 2), ft_putendl_fd(path, 2);
		exit(1);
	}
	if (!(ft_memchr(header->prog_name, 0, PROG_NAME_LENGTH + 1)))
	{
		ft_putstr_fd("corewar: invalide name.\n", 2);
		ft_putstr_fd("file: ", 2), ft_putendl_fd(path, 2);
		exit(1);
	}
	if (!(ft_memchr(header->comment, 0, COMMENT_LENGTH + 1)))
	{
		ft_putstr_fd("corewar: invalide comment.\n", 2);
		ft_putstr_fd("file: ", 2), ft_putendl_fd(path, 2);
		exit(1);
	}
}

static int			init_header(int fd, const char *path)
{
	int			ret;
	t_header	header;

	if ((ret = read(fd, &header, sizeof(t_header))) != sizeof(t_header))
	{
		(ret == -1) ? perror("corewar")
		: ft_putstr_fd("corewar: invalide header.\n", 2);
		ft_putstr_fd("file: ", 2), ft_putendl_fd(path, 2);
		exit(1);
	}
	check_header(&header, path);
	add_player(&header);
	return ((int)header.prog_size);
}

void				load_champ(const char *path)
{
	int		fd;
	int		champ_size;

	if ((fd = open(path, O_RDONLY)) == -1)
	{
		perror("corewar");
		ft_putstr_fd("file: ", 2), ft_putendl_fd(path, 2);
		exit(1);
	}
	champ_size = init_header(fd, path);
	load_prog(fd, champ_size, path);
}

void				write_prog(void)
{
	unsigned	i;
	long		cur_pos;
	long		space;

	space = MEM_SIZE / N_PLAYER;
	i = 0;
	cur_pos = 0;
	while (i < N_PLAYER)
	{
		cp_champion(g_champ[i], cur_pos, i + 1);
		add_process((long)cur_pos, get_player(i + 1));
		LAST_PROC->reg.r[0] = i + 1;
		free(g_champ[i]);
		i++;
		cur_pos += space;
	}
}
