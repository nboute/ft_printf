# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlovato <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/20 10:01:12 by tlovato           #+#    #+#              #
#    Updated: 2017/02/04 21:10:02 by nboute           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./srcs/
INC_PATH = ./inc/
LIBFT_PATH = ./libft/

LIBFT = libft.a

SRC_FILES = ft_printf.c \
	  ft_functions.c \
	  ft_spe1.c \
	  ft_wide.c \
	  ft_width.c \
	  ft_dataflg.c

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

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C $(LIBFT_PATH)
	@cp $(LIBFT_PATH)$(LIBFT) $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm -rf $(OBJ_PATH)
	@$(MAKE) clean -C $(LIBFT_PATH)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
