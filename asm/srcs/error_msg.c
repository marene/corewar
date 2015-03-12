/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 11:08:27 by marene            #+#    #+#             */
/*   Updated: 2015/03/11 16:59:03 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <libft.h>

char	*get_error_msg(t_error code)
{
	static char		*error_table[UNKNOWN + 1] = {

	"usage: ./asm file/to/be/assembled",
	"invalid file: file must be .s",
	"fatal error: file does not exist or is not readable",
	"missing .name",
	"missing .comment",
	"name and / or comment too big",
	"fatal error: .cor file could not be created",
	"champion is too big: .cor file not created",
	"no error",
	"unknown error"
	};
	if (code > UNKNOWN)
		code = UNKNOWN;
	return (error_table[code]);
}

char	*get_serror_msg(t_serror code)
{
	static char		*serror_table[UNKNOWN_SERROR + 1] = {

	"unexpected symbol",
	"unexpected token",
	"unknown opcode",
	"invalid register number",
	"unknown label",
	"invalid parameter",
	"invalid parameter number",
	"invalid parameter value",
	"no error",
	"unknown error"
	};
	if (code > UNKNOWN_SERROR)
		code = UNKNOWN_SERROR;
	return (serror_table[code]);
}
