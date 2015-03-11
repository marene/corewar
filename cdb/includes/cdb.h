/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdb.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 15:00:42 by marene            #+#    #+#             */
/*   Updated: 2015/03/11 12:12:06 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CDB_H
# define CDB_H

# define CDB_OK		0
# define CDB_KO		-1
# define CDB_INDEX	0xc0

int					disassemble(int fd);
int					get_args(int fd, unsigned char *encoding);
unsigned int		change_endianess(unsigned int val);

#endif
