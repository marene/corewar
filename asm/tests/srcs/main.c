/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 11:58:09 by marene            #+#    #+#             */
/*   Updated: 2015/03/05 14:11:43 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <libft.h>
#include <op.h>
#include <test.h>

#include <stdio.h>

t_op	g_op_table[17] =
{
	{"live", 1, {T_DIR, 0, 0}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG, 0}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG, 0}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_INDEX | T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_INDEX | T_REG | T_DIR | T_IND, T_INDEX | T_DIR | T_REG,
			T_REG}, 10, 25, "load index", 1, 1},
	{"sti", 3, {T_REG, T_INDEX | T_REG | T_DIR | T_IND, T_INDEX | T_DIR
			| T_REG}, 11, 25, "store index", 1, 1},
	{"fork", 1, {T_INDEX | T_DIR, 0, 0}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG, 0}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR, 0, 0}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG, 0, 0}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

int		main(void)
{
	int		i;
	int		fd;
	char	*test_ok;
	char	*test_ko;
	char	*tmp;

	i = 0;
	srand(time(NULL));
	while (i < TEST_NB)
	{
		tmp = ft_itoa(i);
		test_ok = (char *)malloc(sizeof(char) * (OK_LEN + EXT_LEN
					+ ft_strlen(tmp) + 1));
		test_ko = (char *)malloc(sizeof(char) * (KO_LEN + EXT_LEN
					+ ft_strlen(tmp) + 1));
		test_ok[0] = '\0';
		test_ko[0] = '\0';
		ft_strcat(test_ok, OK_NAME);
		ft_strcat(test_ok, tmp);
		ft_strcat(test_ok, ASM_EXT);
		ft_strcat(test_ko, KO_NAME);
		ft_strcat(test_ko, tmp);
		ft_strcat(test_ko, ASM_EXT);
		free(tmp);
		tmp = NULL;
		if ((fd = open(test_ok, O_WRONLY | O_CREAT | O_TRUNC, 0755)) >= 0)
		{
			gen_valid_test(fd);
			insert_label(CLEAR_LABELS);
			printf("%s generated\n", test_ok);
			free(test_ok);
			test_ok = NULL;
			close(fd);
		}
		else
			printf("%s could not be generated\n", test_ok);
		if ((fd = open(test_ko, O_WRONLY | O_CREAT | O_TRUNC, 0755)) >= 0)
		{
			gen_invalid_test(fd);
			insert_label(CLEAR_LABELS);
			printf("%s generated\n", test_ko);
			free(test_ko);
			test_ko = NULL;
			close(fd);
		}
		else
			printf("%s could not be generated\n", test_ko);
		++i;
	}
	return (0);
}
