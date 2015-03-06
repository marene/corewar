/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/03 20:26:17 by marene            #+#    #+#             */
/*   Updated: 2015/03/05 14:35:30 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATES_H
# define STATES_H

# include <asm.h>

int			g_state_table[17][12][2] = {
	{{NOS, NOA}, {OPCODE, NOA}, {NOS, NOA}, {NOS, NOA}, {NOS, NOA}, {NOS, NOA},
		{BEG_STDA_LABEL, NOA}, {OPCODE, NOA}, {BEGIN, NOA}, {BEGIN, NOA},
		{COMMENT, NOA}, {PARSE_END, GEN_COR}},
	{{NOS, NOA}, {OPCODE, NOA}, {BEG_STDA_LABEL, NOA}, {NOS, NOA}, {NOS, NOA},
		{BEGIN, GEN_STDA_LABEL}, {BEG_STDA_LABEL, NOA}, {OPCODE, NOA},
		{NEW_ARG, GEN_OPCODE}, {NOS, NOA}, {NOS, NOA}, {NOS, NOA}},
	{{BEG_IND_NUM, NOA}, {NOS, NOA}, {IND_NUM, NOA}, {NOS, NOA},
		{BEG_DIR, NOA}, {BEG_IND_LABEL, NOA}, {NOS, NOA},
		{BEG_REGISTER, NOA},
		{NEW_ARG, NOA}, {NOS, NOA}, {COMMENT, NOA}, {NOS, NOA}},
	{{NOS, NOA}, {NOS, NOA}, {REGISTER, NOA}, {NOS, NOA}, {NOS, NOA},
		{NOS, NOA}, {NOS, NOA},
		{NOS, NOA}, {NOS, NOA}, {NOS, NOA}, {NOS, NOA}, {NOS, NOA}},
	{{NOS, NOA}, {NOS, NOA}, {IND_NUM, NOA}, {NOS, NOA}, {NOS, NOA}, {NOS, NOA},
		{NOS, NOA}, {NOS, NOA}, {NOS, NOA}, {NOS, NOA}, {NOS, NOA}, {NOS, NOA}},
	{{NOS, NOA}, {NOS, NOA}, {IND_NUM, NOA}, {NEW_ARG, GEN_IND_NUM}, {NOS, NOA},
		{NOS, NOA}, {NOS, NOA}, {NOS, NOA}, {WAIT, GEN_IND_NUM},
		{BEGIN, GEN_IND_NUM}, {COMMENT, GEN_IND_NUM}, {NOS, NOA}},
	{{DIR_NUM, NOA}, {NOS, NOA}, {DIR_NUM, NOA}, {NOS, NOA}, {NOS, NOA},
		{BEG_DIR_LABEL, NOA}, {NOS, NOA}, {NOS, NOA}, {NOS, NOA}, {NOS, NOA},
		{NOS, NOA}, {NOS, NOA}},
	{{NOS, NOA}, {NOS, NOA}, {REGISTER, NOA}, {NEW_ARG, GEN_REGISTER},
		{NOS, NOA}, {NOS, NOA}, {NOS, NOA}, {NOS, NOA}, {WAIT, GEN_REGISTER},
		{BEGIN, GEN_REGISTER}, {COMMENT, GEN_REGISTER}, {NOS, NOA}},
	{{NOS, NOA}, {NOS, NOA}, {DIR_NUM, NOA}, {NEW_ARG, GEN_DIR_NUM}, {NOS, NOA},
		{NOS, NOA}, {NOS, NOA}, {NOS, NOA}, {WAIT, GEN_DIR_NUM},
		{BEGIN, GEN_DIR_NUM}, {COMMENT, GEN_DIR_NUM}, {NOS, NOA}},
	{{NOS, NOA}, {DIR_LABEL, NOA}, {DIR_LABEL, NOA}, {NOS, NOA}, {NOS, NOA},
		{NOS, NOA}, {DIR_LABEL, NOA}, {DIR_LABEL, NOA}, {NOS, NOA}, {NOS, NOA},
		{NOS, NOA}, {NOS, NOA}},
	{{NOS, NOA}, {DIR_LABEL, NOA}, {DIR_LABEL, NOA}, {NEW_ARG, GEN_DIR_LABEL},
		{NOS, NOA}, {NOS, NOA}, {DIR_LABEL, NOA}, {DIR_LABEL, NOA},
		{WAIT, GEN_DIR_LABEL}, {BEGIN, GEN_DIR_LABEL}, {COMMENT, GEN_DIR_LABEL},
		{NOS, NOA}},
	{{NOS, NOA}, {IND_LABEL, NOA}, {NOS, NOA}, {NOS, NOA}, {NOS, NOA},
		{NOS, NOA}, {IND_LABEL, NOA}, {IND_LABEL, NOA}, {NOS, NOA}, {NOS, NOA},
		{NOS, NOA}, {NOS, NOA}},
	{{NOS, NOA}, {IND_LABEL, NOA}, {IND_LABEL, NOA}, {NEW_ARG, GEN_IND_LABEL},
		{NOS, NOA}, {NOS, NOA}, {IND_LABEL, NOA}, {IND_LABEL, NOA},
		{WAIT, GEN_IND_LABEL}, {BEGIN, GEN_IND_LABEL}, {COMMENT, GEN_IND_LABEL},
		{NOS, NOA}},
	{{NOS, NOA}, {BEG_STDA_LABEL, NOA}, {BEG_STDA_LABEL, NOA}, {NOS, NOA},
		{NOS, NOA}, {STDA_LABEL, GEN_STDA_LABEL}, {BEG_STDA_LABEL, NOA},
		{BEG_STDA_LABEL, NOA}, {NOS, NOA}, {NOS, NOA}, {NOS, NOA}, {NOS, NOA}},
	{{NOS, NOA}, {NOS, NOA}, {NOS, NOA}, {NOS, NOA}, {NOS, NOA}, {NOS, NOA},
		{NOS, NOA}, {NOS, NOA}, {BEGIN, NOA}, {BEGIN, NOA}, {COMMENT, NOA},
		{NOS, NOA}},
	{{COMMENT, NOA}, {COMMENT, NOA}, {COMMENT, NOA}, {COMMENT, NOA},
		{COMMENT, NOA}, {COMMENT, NOA}, {COMMENT, NOA}, {COMMENT, NOA},
		{COMMENT, NOA}, {BEGIN, NOA}, {COMMENT, NOA}, {COMMENT, NOA}},
	{{NOS, NOA}, {NOS, NOA}, {NOS, NOA}, {NEW_ARG, NOA}, {NOS, NOA}, {NOS, NOA},
		{NOS, NOA}, {NOS, NOA}, {WAIT, NOA}, {BEGIN, NOA}, {COMMENT, NOA},
		{NOS, NOA}}
};
#endif
