/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marene <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/24 11:51:52 by marene            #+#    #+#             */
/*   Updated: 2015/03/09 11:51:39 by marene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <libft.h>
# include <error.h>
# include <op.h>

# define STATE 0
# define ACTION 1
# define _NAME ".name \""
# define _COMMENT ".comment \""
# define COR_EXT ".cor"
# define ASM_OK 1
# define ASM_KO 0

typedef enum	e_type
{
	T_BEGIN,
	T_NAME,
	T_COM,
	T_OPCODE,
	T_IND_NUM,
	T_IND_LABEL,
	T_REGISTER,
	T_DIR_NUM,
	T_DIR_LABEL,
	T_STDA_LABEL
}				t_type;

/*
** enum e_state is an enumeration of all the finished states automaton (FSA)
** states.
*/

typedef enum	e_state
{
	BEGIN,
	OPCODE,
	NEW_ARG,
	BEG_REGISTER,
	BEG_IND_NUM,
	IND_NUM,
	BEG_DIR,
	REGISTER,
	DIR_NUM,
	BEG_DIR_LABEL,
	DIR_LABEL,
	BEG_IND_LABEL,
	IND_LABEL,
	BEG_STDA_LABEL,
	STDA_LABEL,
	COMMENT,
	WAIT,
	NOS,
	PARSE_END
}				t_state;

/*
** enum e_symbol list all the types of symbols that can be read in a source file
*/

typedef enum	e_symbol
{
	SIGN_CHAR,
	AB_CHARS,
	NUM_VAL,
	SEP_CHAR,
	DIR_CHAR,
	LABEL_CHAR,
	LABEL_CHARS,
	REG_CHAR,
	WHITE_SPACE,
	NEWLINE,
	COMMENT_CHAR,
	END
}				t_symbol;

/*
** enum e_action list all the transition actions that can be performed while
** getting from a state to another
*/

typedef enum	e_action
{
	GEN_OPCODE,

	GEN_IND_NUM,
	GEN_REGISTER,
	GEN_DIR_NUM,
	GEN_DIR_LABEL,
	GEN_IND_LABEL,
	GEN_STDA_LABEL,

	GEN_COR,
	NOA
}				t_action;

/*
** struct s_token represents a parsed token in memory.
*/

typedef struct	s_token
{
	char			*content;
	int				value;
	t_type			type;
	int				size;
	int				arg_nb;
	int				linum;
	int				addr;
	struct s_token	*next;
	struct s_token	*args;
}				t_token;

typedef struct	s_syntax
{
	t_serror	serror;
	int			linum;
	int			colnum;
}				t_syntax;

typedef struct	s_env
{
	char		*line;
	int			begin;
	int			end;
	char		name;
	char		comment;
	t_state		current_state;
	t_state		next_state;
	t_syntax	*syntax;
}				t_env;

typedef int		(*t_fct_ptr[8]) (t_token *flow, t_env *env);
typedef int		(*t_act_fct) (t_token *flow, t_env *env);
typedef int		(*t_flow_check_fct) (t_token *flow);

int				get_stda_value(t_token *head, t_token *flow);
void			*serialize_header(t_header *head);
int				gen_opcode(t_token *flow, t_env *env);
int				gen_dir_num(t_token *flow, t_env *env);
int				gen_ind_num(t_token *flow, t_env *env);
int				gen_register(t_token *flow, t_env *env);
int				gen_dir_label(t_token *flow, t_env *env);
int				gen_ind_label(t_token *flow, t_env *env);
int				gen_stda_label(t_token *flow, t_env *env);
int				gen_cor(t_token *flow);
int				insert_header(int fd, t_token *flow);
void			write_bytes(int fd, int val, int size);
int				get_next_action(t_env *env, t_symbol symbol, t_act_fct *fct);
t_env			*env_init(void);
int				lexer(t_env *env, int fd, t_token *flow);
int				parser(t_token *flow);
t_token			*token_flow_init(t_env *env, char *file_name, int fd);
void			action_table_init(void);
t_token			*token_create(char *content, int value, t_type type, int size);
t_error			set_error(t_error code);
void			print_error(void);
t_env			*set_serror(t_env *env, t_serror code);
void			print_serror(void);
char			*get_error_msg(t_error code);
char			*get_serror_msg(t_serror code);
int				add_to_flow(t_env *env, t_token *flow, t_token *new);
t_arg_type		get_argtype(t_type arg);
char			*make_line(t_token *flow);

int				foo(t_token *flow, t_env *env);

#endif
