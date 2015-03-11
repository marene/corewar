/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 14:03:05 by marene            #+#    #+#             */
/*   Updated: 2015/03/09 18:09:03 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

#ifndef OP_H
# define OP_H

# define BYTE					1
# define IND_SIZE				2
# define OP_SIZE				1
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER			4
# define MAX_PLAYERS				4
# define MEM_SIZE				(4*1024)
# define IDX_MOD					(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define C_COMMENT_CHAR				'#'
# define C_LABEL_CHAR				':'
# define C_DIRECT_CHAR				'%'
# define C_SEPARATOR_CHAR			','

/*
** LABEL_CHARS previously was [a-z]_[0-9]. Now [a-z] are considered as AB_CHARS
*/

# define C_LABEL_CHARS				"_0123456789"

# define NAME_CMD_STRING			".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA				50
# define NBR_LIVE				21
# define MAX_CHECKS				10

typedef int			t_arg_type;

# define T_OP					1
# define T_REG					2
# define T_DIR					4
# define T_IND					8
# define T_INDEX				16

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct		s_op
{
	char		*mnemon;
	int			arg_nb;
	t_arg_type	args[3];
	int			op_val;
	int			stuff;
	char		*description;
	int			encoding_byte;
	int			change_carry;
}					t_op;

typedef struct		s_label
{
	char	*name;
	int		value;
}					t_label;

typedef struct		s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					t_header;

#endif
