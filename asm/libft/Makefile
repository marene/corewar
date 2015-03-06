# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marene <marene@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/23 10:20:28 by marene            #+#    #+#              #
#    Updated: 2014/05/18 14:25:27 by marene           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc
AR =		ar
NAME =		libft.a
CFLAGS =	-Wall -Wextra -Werror -I ./includes -c -g -o
LFLAGS =	-q
SRC =		ft_atoi.c				ft_bzero.c\
			ft_isalnum.c			ft_isalpha.c\
			ft_isascii.c			ft_isdigit.c\
			ft_isprint.c			ft_itoa.c\
			ft_memalloc.c			ft_memccpy.c\
			ft_memchr.c				ft_memcmp.c\
			ft_memcpy.c				ft_memdel.c\
			ft_memmove.c			ft_memset.c\
			ft_putchar.c			ft_putchar_fd.c\
			ft_putstr.c				ft_putstr_fd.c\
			ft_putendl.c			ft_putendl_fd.c\
			ft_putnbr.c				ft_putnbr_fd.c\
			ft_strcat.c				ft_strchr.c\
			ft_strclr.c				ft_strcmp.c\
			ft_strcpy.c				ft_strdel.c\
			ft_strdup.c				ft_strequ.c\
			ft_striter.c			ft_striteri.c\
			ft_strjoin.c			ft_strlcat.c\
			ft_strlen.c				ft_strmap.c\
			ft_strmapi.c			ft_strncat.c\
			ft_strncmp.c			ft_strncpy.c\
			ft_strnequ.c			ft_strnew.c\
			ft_strnstr.c			ft_strrchr.c\
			ft_strsplit.c			ft_strstr.c\
			ft_strsub.c				ft_strtrim.c\
			ft_tolower.c			ft_toupper.c\
			error.c					ft_array_free.c\
			ft_array_len.c			ft_isnumber.c\
			ft_epurstr.c			ft_iswhite.c
OBJ = $(SRC:.c=.o)
SRC_DIR = ./srcs/
OBJ_DIR = ./obj/
HEADER_DIR = ./includes

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir $@

test: $(OBJ_DIR) test_build

test_build: $(NAME)
	$(CC) $(CFLAGS) ./obj/main.o ./srcs/main.c
	$(CC) -L ./ -lft ./obj/main.o -o test

$(NAME): $(addprefix $(OBJ_DIR), $(OBJ))
	@echo "\033[A\033[2K"
	@echo "\033[A[LIBFT: COMPILING: \033[0;33mDONE\033[0;32m]\033[0m"
	@$(AR) $(LFLAGS) $@ $^
	@echo "\033[A\033[2K"
	@echo "\033[A\033[0;32m[LIBFT: LINKING: \033[0;33mDONE\033[0;32m]\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "\033[A\033[2K"
	@echo "\033[0;32m\033[A[LIBFT: COMPILING: \033[0;33m$@\033[0;32m]"
	@$(CC) $(CFLAGS) $@ $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
