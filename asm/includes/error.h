/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 12:18:58 by marene            #+#    #+#             */
/*   Updated: 2015/03/13 14:44:56 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <asm.h>

# define NAME "asm: "

# define T_YELLOW "\033[033;m"
# define T_DEFAULT "\033[0m"

typedef enum	e_error
{
	W_USAGE,
	W_FILE_EXT,
	W_FILE,
	M_NAME,
	M_COMMENT,
	NC_TOO_BIG,
	COR_FILE,
	PROG_TOO_BIG,
	NO_ERROR,
	RESET,
	UNKNOWN
}				t_error;

typedef enum	e_serror
{
	U_SYMBOL,
	U_TOKEN,
	U_OPCODE,
	W_REG_NB,
	U_LABEL,
	W_PARAM_TYPE,
	W_PARAM_NB,
	W_PARAM_VAL,
	NO_SERROR,
	S_RESET,
	UNKNOWN_SERROR
}				t_serror;

/*
** t_syntax linum starts at 1, colnum starts at 0
*/

#endif
