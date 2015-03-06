/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 12:26:26 by marene            #+#    #+#             */
/*   Updated: 2015/03/05 14:39:25 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <fcntl.h>
# include <stdlib.h>

# define TEST_OK			0
# define TEST_KO			-1

# define TEST_NB			400
# define OP_REP_NB			10
# define W_CHAR_MAX			5

# define ERR				0
# define NO_ERR				1

/* *_PROBA are in percent*/

# define BAD_NAME_PROBA		10
# define BAD_LINE_PROBA		20
# define RANDOM_SHIT_PROBA	0 /* Set this at 0 if you want to only test bad args */
# define COMMENT_PROBA		10
# define EOL_COMMENT_PROBA	5
# define EMPTY_LINE_PROBA	10
# define LABEL_PROBA		20
# define LABEL_REF_PROBA	40
# define BAD_LABEL_PROBA	10

# define OK_NAME			"okTest"
# define KO_NAME			"koTest"

# define ASM_EXT			".s"
# define CLEAR_LABELS		-42

# define OK_LEN				ft_strlen(OK_NAME)
# define KO_LEN				ft_strlen(KO_NAME)
# define EXT_LEN			ft_strlen(ASM_EXT)
# define COMMENT_MAX_LEN	80

int							gen_valid_test(int fd);
int							gen_invalid_test(int fd);
int							insert_line(int fd, t_op op, int *err);
int							insert_name_comment(int fd);
void						insert_whitespaces(int fd, int n);
char						**insert_label(int fd);

#endif
