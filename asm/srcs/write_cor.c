/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 16:50:14 by marene            #+#    #+#             */
/*   Updated: 2014/06/14 12:47:10 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <error.h>
#include <op.h>

extern t_op		g_op_table[17];

void	write_value(int fd, t_token *token)
{
	char		*val_to_write;
	t_arg_type	type;
	int			byte_nb;
	int			i;
	int			mask;

	i = 0;
	type = get_type(token->type);
	if (type == T_OP)
		byte_nb = OP_SIZE;
	else if (type == T_IND)
		byte_nb = IND_SIZE;
	else
		byte_nb = REG_SIZE;
	val_to_write = (char*)malloc(byte_nb);
	i = byte_nb - 1;
	mask = 0xFF;
	while (i >= 0)
	{
		val_to_write[i] = token->value & mask;
		mask = mask << 8;
		i--;
	}
	write(fd, val_to_write, byte_nb);
	free(val_to_write);
}

void	write_param(int fd, t_token *flow)
{
	t_token		*leaf;

	leaf = flow->leaf;
	while (leaf)
	{
		write_value(fd, leaf);
		leaf = leaf->leaf;
	}
}

void	write_encoding_byte(int fd, t_token *node)
{
	char		coding_byte;
	t_token		*leaf;

	coding_byte = 0;
	leaf = node->leaf;
	while (leaf)
	{
		coding_byte |= get_type(leaf->type);
		leaf = leaf->leaf;
	}
	write(fd, &coding_byte, 1);
}

void	write_cor(t_token *flow)
{
	char	*cor_name;
	t_op	current_op;
	int		fd;

	cor_name = ft_strjoin(flow->content, COR_EXT);
	if ((fd = open(cor_name, O_WRONLY | O_CREAT | O_TRUNC, 0555)) > 0)
	{
		while (flow && flow->type < T_OPCODE)
			flow = flow->node;
		while (flow)
		{
			if (flow->type == T_OPCODE)
			{
				current_op = g_op_table[flow->value - 1];
				write_value(fd, flow);
				if (current_op.encoding_byte)
					write_encoding_byte(fd, flow);
				write_param(fd, flow);
			}
			flow = flow->node;
		}
	}
	else
		set_error(COR_FILE);
}
