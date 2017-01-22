# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlovato <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/20 10:01:12 by tlovato           #+#    #+#              #
#    Updated: 2017/01/13 08:50:58 by nboute           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = gcc
CFLAGS = 

SRC_PATH = ./srcs/
INC_PATH = ./inc/
LIBFT_PATH = ./libft/

LIBFT = libft.a

SRC_FILES = ft_printf.c \
	  ft_functions.c \
	  ft_spe1.c \
	  ft_wide.c \
	  ft_width.c

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))

OBJ_PATH = ./obj/
OBJ_O = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_O))

INC = $(INC_PATH)
INC_CC = $(foreach DIR, $(INC), -I$(DIR))
CFLAGS += $(INC_CC)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -o $@ -c $<

all : $(LIBFT_PATH)$(LIBFT) $(NAME)

$(LIBFT_PATH)$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

$(NAME) : $(OBJ)
	@cp $(LIBFT_PATH)$(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm -f $(OBJ_O)

fclean : clean
	rm -f $(NAME)	

re : fclean all

.PHONY : all clean fclean re
