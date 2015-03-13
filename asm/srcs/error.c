/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 12:04:38 by marene            #+#    #+#             */
/*   Updated: 2015/03/13 14:44:50 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <libft.h>

static void		print_line(char *line, int colnum, t_serror serror)
{
	int		i;

	i = 0;
	(void)serror;
	while (line[i])
	{
		if (i == colnum)
		{
			ft_putstr(T_YELLOW);
			while (line[i] && line[i] != ' ' && line[i] != '\t')
			{
				ft_putchar(line[i]);
				i++;
			}
			ft_putstr(T_DEFAULT);
		}
		if (line[i])
		{
			ft_putchar(line[i]);
			i++;
		}
	}
}

t_env			*set_serror(t_env *env, t_serror code)
{
	static t_env		*e = NULL;

	if (code == S_RESET)
		env_delete(&e);
	else if (env && code != NO_SERROR)
	{
		if (!e)
		{
			e = (t_env*)malloc(sizeof(t_env));
			e->syntax = (t_syntax *)malloc(sizeof(t_syntax));
		}
		if (env->line)
			e->line = ft_strdup(env->line);
		e->begin = env->begin;
		e->end = env->end;
		e->current_state = env->current_state;
		e->next_state = env->next_state;
		e->syntax->serror = code;
		e->syntax->linum = env->syntax->linum;
		e->syntax->colnum = env->syntax->colnum;
	}
	return (e);
}

void			print_serror(void)
{
	t_env		*env;

	env = set_serror(NULL, NO_SERROR);
	if (env != NULL && env->syntax->serror != NO_SERROR)
	{
		ft_putstr(NAME);
		ft_putstr(get_serror_msg(env->syntax->serror));
		ft_putstr(" at line ");
		ft_putnbr(env->syntax->linum);
		if (env->line)
		{
			ft_putstr(", column ");
			ft_putnbr(env->syntax->colnum);
			ft_putstr("\n\t");
			print_line(env->line, env->syntax->colnum, env->syntax->serror);
		}
		ft_putchar('\n');
	}
}

t_error			set_error(t_error code)
{
	static t_error	last_error = NO_ERROR;

	if (code == RESET)
		last_error = NO_ERROR;
	else if (code != NO_ERROR && last_error == NO_ERROR)
		last_error = code;
	return (last_error);
}

void			print_error(void)
{
	t_error		error;

	error = set_error(NO_ERROR);
	if (error != NO_ERROR)
	{
		ft_putstr(NAME);
		ft_putendl(get_error_msg(error));
	}
}
