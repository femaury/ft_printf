# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: femaury <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 20:03:09 by femaury           #+#    #+#              #
#    Updated: 2018/05/13 17:46:37 by femaury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft/libft.a
SRC_PATH = srcs
SRC_NAME = ft_printf.c ft_parsing.c ft_get_arg.c ft_get_int.c ft_fill_buffer.c \
		   ft_pad_buffer.c ft_get_str.c
OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

.PHONY: all, clean, fclean, re, test

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@ar rc $@ $(OBJ)
	@ranlib $@

$(LIBFT):
	$(MAKE) -C libft/ 

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $<

test: $(NAME)
	$(CC) $(CFLAGS) -o printf main.c $^ $(LIBFT)
	@$(RM) $(OBJ)

clean:
	@$(RM) $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@$(MAKE) -C libft/ clean

fclean: clean
	@$(RM) $(NAME)
	@$(RM) printf
	@$(MAKE) -C libft/ fclean

re: fclean all
