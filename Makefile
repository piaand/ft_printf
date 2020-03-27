# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: piaandersin <piaandersin@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/16 11:06:14 by piaandersin       #+#    #+#              #
#    Updated: 2020/03/27 13:10:47 by piaandersin      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ./src/ft_printf.c ./src/assign_struct.c ./src/print_next_var.c \
./src/print_puxX.c ./src/crosscheck_format.c ./src/print_float.c \
./src/add_padding.c

OBJ = $(subst .c,.o,$(subst src/,,$(SRC)))

INCLUDE = ./includes/ft_printf.h

INCL = -I ./includes -I ./libft/includes

LIBFT = ./libft/libft.a

LIB = ar rc $(NAME) $(OBJ)

all: $(NAME)
.PHONY: all
$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc -c -Wall -Wextra -Werror $(SRC) $(INCLUDE)
	$(LIB)

.PHONY: clean
clean:
	/bin/rm -f $(OBJ)
	make -C libft/ clean

.PHONY: fclean
fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all