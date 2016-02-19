/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_cor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 16:01:32 by marene            #+#    #+#             */
/*   Updated: 2016/02/19 16:15:33 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <op.h>
#include <error.h>

extern t_op		g_op_table[17];

static int		get_encoding_byte(t_token *flow)
{
	t_token		*args;
	t_arg_type	type;
	char		byte;
	char		shift;

	byte = 0x0;
	shift = 6;
	args = flow->args;
	while (args)
	{
		type = get_argtype(args->type);
		if (type == T_REG)
			byte |= (REG_CODE << shift);
		else if (type == T_DIR)
			byte |= (DIR_CODE << shift);
		else if (type == T_IND)
			byte |= (IND_CODE << shift);
		args = args->args;
		shift -= 2;
	}
	return (byte);
}

void			write_bytes(int fd, int val, int size)
{
	unsigned char	*to_write;
	int				mask;
	int				shift;
	int				i;

	i = size - 1;
	shift = 0;
	mask = 0xff;
	if ((to_write = (unsigned char *)malloc(sizeof(unsigned char) * size)))
	{
		while (i >= 0)
		{
			to_write[i] = (val & mask) >> shift;
			--i;
			shift += 8;
			mask <<= 8;
		}
		write(fd, to_write, size);
		free(to_write);
	}
}

static int		cor_init(t_token *flow, int *fd)
{
	char	*filename;

	filename = ft_strjoin(flow->content, ".cor");
	if ((*fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0755)) > 0
			&& insert_header(*fd, flow) == ASM_OK)
	{
		free(filename);
		return (ASM_OK);
	}
	free(filename);
	return (ASM_KO);
}

int				gen_cor(t_token *flow)
{
	t_token		*args;
	int			fd;

	if (cor_init(flow, &fd) == ASM_KO && set_error(COR_FILE) != NO_ERROR)
		return (ASM_KO);
	while (flow)
	{
		if (flow->type == T_OPCODE)
		{
			args = flow->args;
			write_bytes(fd, flow->value, flow->size);
			if (g_op_table[flow->value - 1].encoding_byte)
				write_bytes(fd, get_encoding_byte(flow), 1);
			while (args)
			{
				write_bytes(fd, args->value, args->size);
				args = args->args;
			}
		}
		flow = flow->next;
	}
	close(fd);
	return (ASM_OK);
}
