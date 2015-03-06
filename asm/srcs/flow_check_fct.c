/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flow_check_fct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/09 12:18:08 by marene            #+#    #+#             */
/*   Updated: 2015/02/16 10:16:51 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <error.h>
#include <op.h>

extern t_op		g_op_table[17];

flow_check_fct	check_current_opcode(t_token *flow)
{
	t_token		*leaf;
	int			leaf_nb;
	t_op		opcode;

	leaf_nb = 0;
	leaf = flow->leaf;
	opcode = g_op_table[flow->value - 1];
	if (leaf != NULL)
	{
		while (leaf && (get_type(leaf->type) & opcode.args[leaf_nb]))
		{
			leaf_nb++;
			leaf = leaf->leaf;
		}
	}
	else
		set_serror(UNKNOWN_SERROR);
}
