/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_name_comment.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 18:30:19 by marene            #+#    #+#             */
/*   Updated: 2015/02/26 10:09:30 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <op.h>
#include <test.h>

/*
** This code is the worst piece of code I have ever writtent.
** I feel oddly proud of it...
*/

static void		insert_name(int fd)
{
	char		c;
	int			i;
	int			len;
	char		*name;

	insert_whitespaces(fd, 1);
	ft_putstr_fd(".name", fd);
	insert_whitespaces(fd, 0);
	len = (rand() % PROG_NAME_LENGTH) + 1;
	if ((name = (char *)malloc(sizeof(char) * (len + 1))) != NULL)
	{
		i = 0;
		name[len] = '\0';
		while (i < len)
		{
			c = 0;
			while (!ft_isalnum(c))
				c = rand() % 127;
			name[i] = c;
			++i;
		}
		name[0] = '"';
		name[len - 1] = '"';
		ft_putstr_fd(name, fd);
		free(name);
	}
}

static void		insert_comment(int fd)
{
	char	c;
	int		i;
	int		len;
	char	*comment;

	insert_whitespaces(fd, 1);
	ft_putstr_fd(".comment", fd);
	insert_whitespaces(fd, 0);
	len = (rand() % COMMENT_LENGTH) + 1;
	if ((comment = (char *)malloc(sizeof(char) * (len + 1))) != NULL)
	{
		i = 0;
		comment[len] = '\0';
		while (i < len)
		{
			c = 0;
			while (!ft_isalnum(c))
				c = rand() % 127;
			comment[i] = c;
			++i;
		}
		comment[0] = '"';
		comment[len - 1] = '"';
		ft_putstr_fd(comment, fd);
		free (comment);
	}
}

int				insert_name_comment(int fd)
{
	if (rand() % 2 == 0)
	{
		insert_name(fd);
		ft_putchar_fd('\n', fd);
		insert_comment(fd);
		ft_putchar_fd('\n', fd);
	}
	else
	{
		insert_comment(fd);
		ft_putchar_fd('\n', fd);
		insert_name(fd);
		ft_putchar_fd('\n', fd);
	}
	return (0);
}
