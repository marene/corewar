/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 09:45:45 by marene            #+#    #+#             */
/*   Updated: 2015/02/24 17:40:02 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>
#include <error.h>

t_fct_ptr		g_action_table;

void			action_table_init(void)
{
	g_action_table[GEN_OPCODE] = gen_opcode;
	g_action_table[GEN_IND_NUM] = gen_ind_num;
	g_action_table[GEN_REGISTER] = gen_register;
	g_action_table[GEN_DIR_NUM] = gen_dir_num;
	g_action_table[GEN_DIR_LABEL] = gen_dir_label;
	g_action_table[GEN_IND_LABEL] = gen_ind_label;
	g_action_table[GEN_STDA_LABEL] = gen_stda_label;
	g_action_table[GEN_COR] = NULL;
}
