# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nboute <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/04 20:02:22 by nboute            #+#    #+#              #
#    Updated: 2017/02/07 22:57:29 by nboute           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: make all clean fclean re

NAME = libftprintf.a

LIB = -L libft/ -lft

LIBFT = libft/libft.a

CFLAGS = -c -Wall -Wextra -Werror

CC = gcc

C_DIR = srcs/

SRCS = ft_printf.c \
	  ft_functions.c \
	  ft_spe1.c \
	  ft_wide.c \
	  ft_width.c \
	  ft_dataflg.c

SRC = $(addprefix $(C_DIR), $(SRCS))

OBJ = $(SRCS:.c=.o)

INC = -I includes -I libft/

all : $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp $(LIBFT) $(NAME)
	rm -f $(LIBFT)
	ar rc $(NAME) $^

$(LIBFT):
	make -C libft/

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) $^ $(INC)

clean :
	make clean -C libft/
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
