# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nperrin <nperrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 19:45:10 by nperrin           #+#    #+#              #
#    Updated: 2014/12/17 23:15:36 by nperrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	corewar

SRC = 	srcs/*.c\
		srcs/**/*.c

OBJ = 	*.o

FLG	=	-Wall -Werror -Wextra

INC	=	includes/

all		: $(NAME)

$(NAME)	:
		make -C libft/
		gcc $(FLG) -c $(SRC) -I $(INC) -I libft/includes
		gcc -o $(NAME) $(OBJ) -L libft -lft -I $(INC) -I libft/includes

clean	:
	rm -f $(OBJ)

fclean	: clean
	rm -f $(NAME)

re		: fclean $(NAME)
