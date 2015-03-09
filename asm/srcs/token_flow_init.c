/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_flow_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 12:02:05 by marene            #+#    #+#             */
/*   Updated: 2015/03/09 16:33:00 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <error.h>
#include <libft.h>
#include <get_next_line.h>

static int		add_name(t_token *flow, char *content)
{
	t_token		*name;
	char		*epur;
	char		*tmp;
	int			i;

	epur = ft_epurstr(content);
	tmp = epur + ft_strlen(_NAME);
	i = 0;
	while (tmp[i] && tmp[i] != '\"')
		++i;
	if (tmp[i] == '\"')
	{
		tmp = ft_strsub(tmp, 0, i);
		name = token_create(tmp, 0, T_NAME, 0);
		add_to_flow(NULL, flow, name);
		free(tmp);
		free(epur);
		return (ASM_OK);
	}
	else
		set_error(M_NAME);
	free(epur);
	return (ASM_KO);
}

static int		add_comment(t_token *flow, char *content)
{
	t_token		*comment;
	char		*epur;
	char		*tmp;
	int			i;

	epur = ft_epurstr(content);
	tmp = epur + ft_strlen(_COMMENT);
	i = 0;
	while (tmp[i] && tmp[i] != '\"')
		++i;
	if (tmp[i] == '\"')
	{
		tmp = ft_strsub(tmp, 0, i);
		comment = token_create(tmp, 0, T_COM, 0);
		add_to_flow(NULL, flow, comment);
		free(tmp);
		free(epur);
		return (ASM_OK);
	}
	else
		set_error(M_COMMENT);
	free(epur);
	return (ASM_KO);
}

static int		is_comment(char *s)
{
	int		i;

	i = 0;
	if (ft_strlen(s) == 0)
		return (1);
	while (s[i] && ft_iswhite(s[i]))
		++i;
	return ((s[i] == '#') ? 1 : 0);
}

static int		get_content(t_token *new_flow, char *content, char *nc)
{
	char	*tmp;

	if ((tmp = ft_strstr(content, NAME_CMD_STRING)) != NULL)
	{
		if (((nc[0] != 0 && tmp < ft_strchr(content, '"'))
					|| add_name(new_flow, content) == ASM_KO))
			return (ASM_KO);
		else
			nc[0] = 1;
	}
	else if ((tmp = ft_strstr(content, COMMENT_CMD_STRING)) != NULL)
	{
		if (((nc[1] != 0 && tmp < ft_strchr(content, '"'))
					|| add_comment(new_flow, content) == ASM_KO))
			return (ASM_KO);
		else
			nc[1] = 1;
	}
	else if (!is_comment(content))
		return (ASM_KO);
	free(content);
	return (ASM_OK);
}

t_token			*token_flow_init(t_env *env, char *file_name, int fd)
{
	t_token		*new_flow;
	char		*content;
	char		nc[2];
	int			len;

	ft_memset(nc, 0, 2 * sizeof(char));
	len = ft_strlen(file_name);
	new_flow = NULL;
	if (len > 2 && file_name[len - 1] == 's' && file_name[len - 2] == '.')
	{
		content = ft_strsub(file_name, 0, len - 2);
		new_flow = token_create(content, 0, T_BEGIN, 0);
		free(content);
		content = NULL;
		while ((!nc[0] || !nc[1]) && get_next_line(fd, &content) == 1)
		{
			++(env->syntax->linum);
			if (get_content(new_flow, content, nc) == ASM_KO)
				return (NULL);
		}
	}
	else
		set_error(W_FILE_EXT);
	return (new_flow);
}
