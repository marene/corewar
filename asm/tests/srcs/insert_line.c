/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 13:47:39 by marene            #+#    #+#             */
/*   Updated: 2015/03/05 14:11:12 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <op.h>
#include <test.h>

#include <stdio.h>

extern t_op		g_op_table[17];

void		insert_whitespaces(int fd, int n)
{
	int			i;
	int			w_nb;
	char		c;

	i = 0;
	w_nb = (rand() % W_CHAR_MAX) + 1 - n;
	while (i < w_nb)
	{
		c = (rand() % 2 == 0) ? ' ' : '\t';
		ft_putchar_fd(c, fd);
		++i;
	}
}

static void		insert_random_shit(int fd)
{
	int		i;
	int		n;
	char	bs[101];

	n = rand() % 100;
	if (n < 33)
	{
		i = 0;
		while (i < n)
		{
			bs[i] = (rand() % 127) + 1;
			++i;
		}
		bs[n - 1] = '\n';
		bs[n] = '\0';
		ft_putstr_fd(bs, fd);
	}
	else if (n < 66)
		ft_putchar_fd('\n', fd);
	else
	{
		n = NO_ERR;
		insert_line(fd, g_op_table[rand() % 16], &n);
	}
}

static void		insert_comment(int fd)
{
	int		i;
	int		len;
	char	c;

	insert_whitespaces(fd, 1);
	ft_putchar_fd('#', fd);
	i = 0;
	len = rand() % COMMENT_MAX_LEN;
	while (i < len)
	{
		c = (rand() % 127);
		if (ft_isprint(c) && c != '\n')
		{
			ft_putchar_fd(c, fd);
			++i;
		}
	}
}

char			**insert_label(int fd)
{
	int				i;
	int				len;
	static char		**label = NULL;
	char			**tmp;

	if (fd >= 0)
	{
		i = 0;
		len = 0;
		while (label != NULL && label[len] != NULL)
			++len;
		tmp = (char **)malloc(sizeof(char *) * (len + 2));
		tmp[len + 1] = NULL;
		while (label && label[i] != NULL)
		{
			tmp[i] = ft_strdup(label[i]);
			free(label[i]);
			++i;
		}
		free(label);
		label = tmp;
		label[len] = (char *)malloc(sizeof(char) * 11);
		label[len][10] = '\0';
		i = 0;
		while (i < 10)
		{
			label[len][i] = (rand() % 26) + 'a';
			++i;
		}
		ft_putstr_fd(label[len], fd);
		ft_putchar_fd(':', fd);
		insert_whitespaces(fd, 0);
		if (rand() % 2 == 0)
			ft_putchar_fd('\n', fd);
	}
	else if (fd == CLEAR_LABELS)
	{
		i = 0;
		while (label[i] != NULL)
		{
			free(label[i]);
			++i;
		}
		free(label);
		label = NULL;
	}
	return (label);
}

static int		insert_label_ref(int fd)
{
	char	**labels;
	int		i;

	labels = insert_label(-1);
	if (labels)
	{
		i = 0;
		while (labels[i])
			++i;
		i = rand() % i;
		ft_putchar_fd(':', fd);
		ft_putstr_fd(labels[i], fd);
		return (TEST_OK);
	}
	return (TEST_KO);
}

static void		insert_arguments(int fd, t_op op, int *err)
{
	int				i;
	int				j;
	char			*tmp;
	char			c;
	char			bad_arg;
	t_arg_type		args[3] = {T_REG, T_DIR, T_IND};

	i = 0;
	while (i < op.arg_nb)
	{
		j = rand() % 3;
		bad_arg = (rand() % 100 < BAD_LINE_PROBA && *err == ERR) ? 1 : 0;
		while ((args[j] & op.args[i]) == bad_arg)
				j = rand() % 3;
		if (args[j] == T_REG)
		{
			tmp = ft_itoa((rand() % 16) + 1);
			if (*err == ERR && rand() % 100 < RANDOM_SHIT_PROBA
					&& bad_arg == 0 && (c = rand() % 127) != '\n')
			{
				*err = NO_ERR;
				ft_putchar_fd(c, fd);
			}
			else
				ft_putchar_fd('r', fd);
			ft_putstr_fd(tmp, fd);
			free(tmp);
			tmp = NULL;
		}
		else
		{
			if (args[j] == T_DIR)
			{
				if (*err == ERR && rand() % 100 < RANDOM_SHIT_PROBA
					&& bad_arg == 0 && (c = rand() % 127) != C_DIRECT_CHAR)
				{
					*err = NO_ERR;
					ft_putchar_fd(c, fd);
				}
				else
					ft_putchar_fd(C_DIRECT_CHAR, fd);
			}
			if (rand() % 100 >= LABEL_REF_PROBA || insert_label_ref(fd) == TEST_KO)
			{
				if (args[j] == T_IND || (op.args[i] & T_INDEX) != 0)
					tmp = ft_itoa((rand() % 0xffff));
				else
					tmp = ft_itoa((rand() % 0xffffffff));
				ft_putstr_fd(tmp, fd);
				free(tmp);
				tmp = NULL;
			}
		}
		insert_whitespaces(fd, 1);
		if (i + 1 < op.arg_nb)
		{
			ft_putchar_fd(C_SEPARATOR_CHAR, fd);
			insert_whitespaces(fd, 1);
		}
		++i;
	}
	if ((rand() % 100) < EOL_COMMENT_PROBA)
		insert_comment(fd);
	ft_putchar_fd('\n', fd);
}

int				insert_line(int fd, t_op op, int *err)
{
	insert_whitespaces(fd, 1);
	if (rand() % 100 < LABEL_PROBA)
		insert_label(fd);
	if (rand() % 100 < RANDOM_SHIT_PROBA && *err == ERR)
	{
		*err = NO_ERR;
		insert_random_shit(fd);
	}
	else
		ft_putstr_fd(op.mnemon, fd);
	insert_whitespaces(fd, 0);
	insert_arguments(fd, op, err);
	if ((rand() % 100) < COMMENT_PROBA)
	{
		insert_comment(fd);
		ft_putchar_fd('\n', fd);
	}
	if ((rand() % 100) < EMPTY_LINE_PROBA)
		ft_putchar_fd('\n', fd);
	return (0);
}
