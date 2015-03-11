NAME =				cdb
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
SRCS =				main.c				disassemble.c\
					change_endianess.c	get_args.c
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
