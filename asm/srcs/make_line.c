/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 11:50:35 by marene            #+#    #+#             */
/*   Updated: 2015/03/09 12:34:25 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <asm.h>

static char		*get_spec_char(t_token *flow, char *line)
{
	char	*tmp;
	char	dir[2];
	char	reg[2];

	dir[0] = C_DIRECT_CHAR;
	dir[1] = '\0';
	reg[0] = 'r';
	reg[1] = '\0';
	if (flow->type == T_REGISTER)
	{
		tmp = line;
		line = ft_strjoin(line, reg);
		free(tmp);
	}
	else if (flow->type == T_DIR_NUM || flow->type == T_DIR_LABEL)
	{
		tmp = line;
		line = ft_strjoin(line, dir);
		free(tmp);
	}
	return (line);
}

char			*make_line(t_token *flow)
{
	char		*line;
	char		*tmp;
	t_token		*f;

	line = ft_strdup(flow->content);
	f = flow;
	flow = flow->args;
	while (flow)
	{
		tmp = line;
		if (flow != f->args)
			line = ft_strjoin(line, ", ");
		else
			line = ft_strjoin(line, " ");
		free(tmp);
		line = get_spec_char(flow, line);
		tmp = line;
		line = ft_strjoin(line, flow->content);
		free(tmp);
		flow = flow->args;
	}
	return (line);
}
