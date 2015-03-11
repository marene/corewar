/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 12:09:57 by marene            #+#    #+#             */
/*   Updated: 2015/03/11 12:43:56 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <op.h>
#include <cdb.h>

static int	get_arg_size(unsigned char encoding, int *size)
{
	if ((encoding & REG_CODE) != 0)
		{
			ft_putstr("register");
			*size = 1;
		}
		else if ((encoding & DIR_CODE) != 0)
		{
			ft_putchar(C_DIRECT_CHAR);
			*size = ((encoding & CDB_INDEX) == 0) ? DIR_SIZE : IND_SIZE;
		}
		else if ((encoding & IND_CODE) != 0)
			*size = IND_SIZE;
		else
			return (CDB_KO);
		return (CDB_OK);
}

int			get_args(int fd, unsigned char *encoding)
{
	int				i;
	int				size;
	unsigned int	val;

	i = 0;
	while (i < 3 && encoding[i] != 0)
	{
		if (get_arg_size(encoding[i], &size) == CDB_OK)
		{
			ft_bzero(&val, sizeof(int));
			if (read(fd, &val, size) != size)
				return (CDB_KO);
			ft_putnbr(change_endianess(val));
			if (i + 1 < 3 && encoding[i + 1] != 0)
				ft_putstr(", ");
		}
		++i;
	}
	ft_putchar('\n');
	return (CDB_OK);
}
