/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 14:45:10 by nperrin           #+#    #+#             */
/*   Updated: 2014/11/18 15:10:08 by nperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H

typedef struct				s_file
{
	int						fd;
	char					*buf;
	char					*ptr;
	char					*end;
}							t_file;

#endif
