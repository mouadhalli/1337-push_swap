# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhalli <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/30 20:10:59 by mhalli            #+#    #+#              #
#    Updated: 2021/05/30 20:11:02 by mhalli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap

SRC = push_swap.c

FLAGS = -Wall -Wextra -Werror -g

MOMALA7AT = -fsanitize=address

LIBS = libft/libft.a \

all: $(NAME)

$(NAME):
	@make --no-print-directory -C libft
	@gcc $(FLAGS) $(SRC) $(LIBS) -o $(NAME)

clean:
	@make --no-print-directory -C libft clean

fclean: clean
	@make --no-print-directory -C libft fclean
	@rm -f $(NAME)

re:	fclean all
