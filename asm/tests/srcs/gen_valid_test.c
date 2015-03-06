/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_valid_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 13:35:57 by marene            #+#    #+#             */
/*   Updated: 2015/02/26 15:59:24 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <op.h>
#include <test.h>

#include <stdio.h>

extern t_op		g_op_table[17];

int				gen_valid_test(int fd)
{
	int			i;
	int			j;
	int			err;

	err = NO_ERR;
	insert_name_comment(fd);
	i = 0;
	while (i < 16)
	{
		j = 0;
		while (j < OP_REP_NB)
		{
			insert_line(fd, g_op_table[i], &err);
			++j;
		}
		++i;
	}
	return (TEST_OK);
}
