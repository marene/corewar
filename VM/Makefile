NAME =				corewar
CC =				gcc
LIB =				ft
LIB_DIR =			./libft/
LIB_INCLUDES =		$(LIB_DIR)includes/
LIBFT =				$(LIB_DIR)libft.a
INCLUDES =			./includes/
CFLAGS =			-Wall -Wextra -Werror\
					-I$(LIB_INCLUDES) -I$(INCLUDES) -c -g -o
LDFLAGS =			-L$(LIB_DIR) -l$(LIB) -o
SRC_DIR =			./srcs/
OBJ_DIR =			./obj/
SRCS =				main.c					arena.c\
					arg.c					cadd.c\
					caff.c					cand.c\
					cdata.c					cfork.c\
					champion.c				check.c\
					check.c					cld.c\
					cldi.c					clfork.c\
					clive.c					clld.c\
					clldi.c					cor.c\
					cp_champion.c			cst.c\
					csti.c					csub.c\
					cxor.c					czjmp.c\
					dump_mem.c				exec_process.c\
					init_arg.c				load_flag.c\
					load_path.c				load_prog.c\
					move_process.c			op.c\
					player.c				process.c
OBJ =				$(SRCS:.c=.o)

all: $(LIBFT) $(OBJ_DIR) $(NAME)

$(LIBFT):
	make -C $(LIB_DIR)

$(OBJ_DIR):
	mkdir $@

$(NAME): $(addprefix $(OBJ_DIR), $(OBJ))
	$(CC) $(LDFLAGS) $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $@ $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean libre all

libre:
	make -C $(LIB_DIR) re

.PHONY: all clean fclean libre
