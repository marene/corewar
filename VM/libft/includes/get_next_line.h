/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 10:51:21 by nperrin           #+#    #+#             */
/*   Updated: 2014/12/16 11:11:10 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 256

typedef struct	s_gnl_save
{
	int			fd;
	char		*str;
	int			size;

}				t_gnl_save;

int				get_next_line(const int fd, char **line);

#endif
