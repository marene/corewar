/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 11:43:36 by marene            #+#    #+#             */
/*   Updated: 2015/03/09 16:46:19 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <op.h>
#include <error.h>

extern t_op				g_op_table[17];

static unsigned int		get_prog_size(t_token *flow)
{
	unsigned int	ret;
	t_token			*args;
	t_op			op;

	ret = 0;
	while (flow)
	{
		if (flow->type == T_OPCODE)
		{
			op = g_op_table[flow->value - 1];
			args = flow->args;
			ret += (unsigned int)flow->size;
			if (op.encoding_byte)
				++ret;
			while (args)
			{
				ret += (unsigned int)args->size;
				args = args->args;
			}
		}
		flow = flow->next;
	}
	return (ret);
}

static unsigned int		change_endianess(unsigned int val)
{
	unsigned int	a0;
	unsigned int	a1;
	unsigned int	a2;
	unsigned int	a3;

	a0 = (val & 0x000000ff) << 24;
	a1 = (val & 0x0000ff00) << 8;
	a2 = (val & 0x00ff0000) >> 8;
	a3 = (val & 0xff000000) >> 24;
	return (a0 | a1 | a2 | a3);
}

static char				*get_name(t_token *flow)
{
	while (flow && flow->type != T_NAME)
		flow = flow->next;
	if (flow)
		return (flow->content);
	else
		return (NULL);
}

static char				*get_comment(t_token *flow)
{
	while (flow && flow->type != T_COM)
		flow = flow->next;
	if (flow)
		return (flow->content);
	else
		return (NULL);
}

int						insert_header(int fd, t_token *flow)
{
	t_header	*head;
	char		*name;
	char		*comment;

	head = (t_header *)malloc(sizeof(t_header));
	ft_bzero(head, sizeof(t_header));
	head->magic = change_endianess(COREWAR_EXEC_MAGIC);
	name = get_name(flow);
	comment = get_comment(flow);
	ft_bzero(head->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(head->comment, COMMENT_LENGTH + 1);
	ft_strcpy(head->prog_name, name);
	ft_strcpy(head->comment, comment);
	head->prog_size = change_endianess(get_prog_size(flow));
	write(fd, head, sizeof(*head));
	free(head);
	return (ASM_OK);
}
