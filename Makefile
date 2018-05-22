# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: femaury <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 20:03:09 by femaury           #+#    #+#              #
#    Updated: 2018/05/22 11:46:28 by femaury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft/libft.a
SRC_PATH = srcs
SRC_NAME = ft_printf.c ftp_parsing.c ftp_get_arg.c ftp_get_int.c \
		   ftp_fill_buffer.c ftp_pad_buffer.c ftp_get_str.c ftp_imaxtoa_base.c \
		   ftp_uimaxtoa_base.c ftp_get_wstr.c ftp_check_wstr.c
LIB_SRC_PATH = libft
LIB_SRC_NAME = ft_strlen.c ft_strdel.c ft_putstr.c ft_strnclr.c ft_setlowcase.c \
			   ft_isdigit.c ft_islower.c ft_strcmp.c ft_atoi.c ft_memalloc.c \
			   ft_memset.c ft_isupper.c ft_strchr.c ft_wcharlen.c ft_wstrlen.c
OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_OBJ_PATH = libft
LIB_OBJ_NAME = $(LIB_SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
LIB_SRC = $(addprefix $(LIB_SRC_PATH)/,$(LIB_SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIB_OBJ = $(addprefix $(LIB_OBJ_PATH)/,$(LIB_OBJ_NAME))
CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re, test, testclean

all: $(NAME)

$(NAME): $(OBJ) $(LIB_OBJ)
	@ar rc $@ $(OBJ) $(LIB_OBJ)
	@ranlib $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -Iincludes -o $@ -c $<

$(LIB_OBJ_PATH)/%.o: $(LIB_SRC_PATH)/%.c
	@$(CC) $(CFLAGS) -Ilibft/includes -o $@ -c $<

test: $(NAME)
	$(CC) -Iincludes -o printf main.c $^
	@$(RM) $(OBJ)

clean:
	@$(RM) $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@$(MAKE) -C libft/ clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C libft/ fclean

testclean: fclean
	@$(RM) printf

re: fclean all
