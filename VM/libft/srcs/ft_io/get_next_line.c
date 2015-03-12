/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 16:38:27 by nperrin           #+#    #+#             */
/*   Updated: 2014/12/16 11:11:36 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

static void		save_save(char *ptr, int size, t_gnl_save *save)
{
	ft_memcpy(save->str, ptr, size);
	save->size = size;
}

static t_list	**load_list(int fd, char **line)
{
	static t_list	*lst;
	t_gnl_save		*save;
	t_gnl_save		new;
	t_list			**ptr;

	if (fd < 0 || !line)
		return (NULL);
	ptr = &lst;
	while (*ptr)
	{
		save = (*ptr)->content;
		if (save->fd == fd)
			break ;
		ptr = &(*ptr)->next;
	}
	if (*ptr)
		return (ptr);
	ft_bzero(&new, sizeof(t_gnl_save));
	new.fd = fd;
	if (!(*ptr = ft_lstnew(&new, sizeof(t_gnl_save))))
		return (NULL);
	return (ptr);
}

static int		load_save(t_list **lst, int *size, char buf[], char **ptr)
{
	t_gnl_save	*save;

	save = (*lst)->content;
	*size = save->size;
	if (*size == 0)
		return (0);
	if (!(*ptr = ft_memchr(save->str, '\n', save->size)))
	{
		ft_memcpy(buf, save->str, *size);
		save->size = 0;
		return (0);
	}
	*size = (int)(*ptr - save->str);
	ft_memcpy(buf, save->str, *size);
	save_save(*ptr + 1, save->size - *size - 1, save);
	return (1);
}

static int		read_line(int const fd, char **line, int size, t_list **lst)
{
	char	buf[BUFF_SIZE];
	int		buf_size;
	int		ret;
	char	*ptr;

	if ((buf_size = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	if ((ptr = ft_memchr(buf, '\n', buf_size)))
	{
		save_save(ptr + 1, buf_size - (int)(ptr - buf) - 1, (*lst)->content);
		buf_size = (int)(ptr - buf);
	}
	if (BUFF_SIZE != buf_size)
	{
		if (!(*line = malloc(size + buf_size + 1)))
			return (-1);
		ft_memcpy(*line + size, buf, buf_size);
		(*line)[size + buf_size] = '\0';
		return (ptr ? 1 : 0);
	}
	if ((ret = read_line(fd, line, size + buf_size, lst)) == -1)
		return (-1);
	ft_memcpy(*line + size, buf, buf_size);
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	t_list				**lst;
	char				buf[BUFF_SIZE];
	void				*ptr;
	int					size;
	int					i;

	if (!(lst = load_list(fd, line)))
		return (-1);
	if ((load_save(lst, &size, buf, (char **)&ptr)))
	{
		if (!(*line = (char *)malloc(size + 1)))
			return (-1);
		ft_memcpy(*line, buf, size);
		(*line)[size] = '\0';
		return (ptr ? 1 : 0);
	}
	if ((i = read_line(fd, line, size, lst)) < 1)
	{
		free((*lst)->content);
		ptr = (*lst)->next;
		free (*lst);
		*lst = ptr;
	}
	ft_memcpy(*line, buf, i == -1 ? 0 : size);
	return (i);
}
