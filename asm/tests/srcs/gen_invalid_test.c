/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_invalid_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/26 15:25:23 by marene            #+#    #+#             */
/*   Updated: 2015/03/09 12:51:17 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <op.h>
#include <test.h>

extern t_op		g_op_table[17];

/*
** name missing
** comment missing
** name too big
** comment too big
** same line
*/

static void		insert_bad_name_comment(int fd)
{
	int		n;
	int		i;
	char	c;
	int		lim;

	i = 0;
	n = rand() % 100;
	if (n < 20)
		ft_putstr_fd(".comment \"foo\"\n", fd);
	else if (n < 40)
		ft_putstr_fd(".name \"bar\"\n", fd);
	else
	{
		ft_putstr_fd("\".name \"", fd);
		if (n < 60)
			lim = PROG_NAME_LENGTH + 1;
		else
			lim = PROG_NAME_LENGTH;
		while (i < lim)
		{
			c = 0;
			while (!ft_isprint(c))
				c = rand() % 127;
			ft_putchar_fd(c, fd);
			++i;
		}
		if (n < 80)
			ft_putchar_fd('"', fd);
		else
			ft_putstr_fd("\"\n", fd);
		if (n < 100)
			lim = COMMENT_LENGTH + 1;
		else
			lim = COMMENT_LENGTH;
		i = 0;
		while (i < lim)
		{
			c = 0;
			while (!ft_isprint(c))
				c = rand() % 127;
			ft_putchar_fd(c, fd);
			++i;
		}
		ft_putstr_fd("\"\n", fd);
	}
}

int				gen_invalid_test(int fd, int err)
{
	int			i;
	int			j;
	int			n;
	int			t;

	i = 0;
	n = rand() % 100;
	if (n > 1)
	{
		if (n > BAD_NAME_PROBA)
			insert_name_comment(fd);
		else
			insert_bad_name_comment(fd);
	}
	while (i < 16)
	{
		if (i == err)
			t = ERR;
		else
			t = NO_ERR;
		j = 0;
		while (j < OP_REP_NB)
		{
			insert_line(fd, g_op_table[i], &t);
			++j;
		}
		++i;
	}
	return (TEST_OK);
}
