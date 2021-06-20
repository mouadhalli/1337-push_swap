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

NAME = push_swap

SRC = push_swap.c actions.c node_utils.c pushswap_utils.c

FLAGS = -Wall -Wextra -Werror -g

MOMALA7AT = -fsanitize=address

LIBS = libft/libft.a \

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc -g $(MOMALA7AT) $(SRC) $(LIBS) -o $(NAME)

clean:
	@make -C libft clean

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re:	fclean all