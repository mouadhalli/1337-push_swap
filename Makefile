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
BONUS_NAME = checker

SRC = push_swap.c buff_utils.c error_utils.c stack_constructor.c stack_destructor.c \
		Actions/push_stack.c Actions/rotate_stack.c Actions/swap_stack.c Actions/actions_utils.c\
		sorting_srcs/big_stack.c sorting_srcs/small_stack.c sorting_srcs/sorting_utils.c

BONUS_SRC = checker.c buff_utils.c error_utils.c stack_constructor.c stack_destructor.c Actions/push_stack.c \
		Actions/push_stack.c Actions/rotate_stack.c Actions/swap_stack.c Actions/actions_utils.c\
		sorting_srcs/big_stack.c sorting_srcs/small_stack.c sorting_srcs/sorting_utils.c

FLAGS = -Wall -Wextra -Werror

MOMALA7AT = -fsanitize=address

LIBS = libft/libft.a \

all: $(NAME)
bonus: $(BONUS_NAME)

$(NAME):
	@make --no-print-directory -C libft
	@gcc $(MOMALA7AT) $(SRC) $(LIBS) -g -o $(NAME)

$(BONUS_NAME):
	@make --no-print-directory -C libft
	@gcc $(MOMALA7AT) $(BONUS_SRC) $(LIBS) -g -o $(BONUS_NAME)

clean:
	@make --no-print-directory -C libft clean

fclean: clean
	@make --no-print-directory -C libft fclean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

re:	fclean all