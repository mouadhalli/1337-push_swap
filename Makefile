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

SRC = push_swap.c sorting_src/buff_utils.c error_utils.c stack_constructor.c stack_destructor.c \
		Actions/push_stack.c Actions/rotate_stack.c Actions/swap_stack.c Actions/actions_utils.c\
		sorting_src/big_stack.c sorting_src/small_stack.c sorting_src/sorting_utils.c \
		ps_utils/ps_atoi.c ps_utils/ps_strlen.c ps_utils/ps_putstr.c ps_utils/ps_split.c ps_utils/ps_isdigit.c \
		ps_utils/ps_putchar.c ps_utils/ps_strncmp.c ps_utils/ps_calloc.c ps_utils/ps_bzero.c

BONUS_SRC = checker.c sorting_src/buff_utils.c error_utils.c stack_constructor.c stack_destructor.c \
		Actions/push_stack.c Actions/rotate_stack.c Actions/swap_stack.c Actions/actions_utils.c\
		sorting_src/big_stack.c sorting_src/small_stack.c sorting_src/sorting_utils.c \
		GNL/get_next_line.c GNL/get_next_line_utils.c \
		ps_utils/ps_atoi.c ps_utils/ps_strlen.c ps_utils/ps_putstr.c ps_utils/ps_split.c ps_utils/ps_isdigit.c \
		ps_utils/ps_putchar.c ps_utils/ps_strncmp.c ps_utils/ps_calloc.c ps_utils/ps_bzero.c

FLAGS = -Wall -Wextra -Werror -fsanitize=address

LIBS = libft/libft.a \

all: $(NAME)
bonus: $(BONUS_NAME)

$(NAME):
	@gcc $(FLAGS) $(SRC) -g -o $(NAME)

$(BONUS_NAME):
	@gcc $(FLAGS) $(BONUS_SRC) -g -o $(BONUS_NAME)

clean:
	@rm -rf *.o

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

re:	fclean all