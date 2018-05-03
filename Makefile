# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: femaury <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 20:03:09 by femaury           #+#    #+#              #
#    Updated: 2018/05/03 14:41:16 by femaury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC_PATH = .
SRC_NAME = ft_strnew.c ft_strdel.c ft_strlen.c ft_strnjoin.c ft_putstr.c \
		   ft_memcpy.c ft_memmove.c
OBJ_PATH = .
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re, test

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@$(RM) $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $^

test: $(NAME)
	$(CC) $(CFLAGS) ft_printf.c $^

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
