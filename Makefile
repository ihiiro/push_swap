# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 17:42:48 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/02/07 12:24:58 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CFLAGS = -Wall -Wextra -Werror
PARSING = parsing/verify.c parsing/exitf.c parsing/push.c parsing/satoi.c
OPS = ops/swap.c ops/push.c ops/rotate.c ops/rrotate.c
PARSING_BONUS = _bonus/parsing/verify_bonus.c _bonus/parsing/exitf_bonus.c _bonus/parsing/push_bonus.c _bonus/parsing/satoi_bonus.c
OPS_BONUS = _bonus/ops/swap_bonus.c _bonus/ops/push_bonus.c _bonus/ops/rotate_bonus.c _bonus/ops/rrotate_bonus.c
GET_NEXT_LINE_BONUS = _bonus/get_next_line/get_next_line.c _bonus/get_next_line/get_next_line_utils.c

all: $(NAME)
$(NAME): main.c list.c squish_sort.c $(PARSING) $(OPS) $(PUSH_SWAP_TOOLS) push_swap.h
	cc $(CFLAGS) main.c squish_sort.c $(PARSING) $(OPS) $(PUSH_SWAP_TOOLS) list.c -o $@
bonus: $(NAME_BONUS)
$(NAME_BONUS): _bonus/checker_bonus.c _bonus/helpers_bonus.c _bonus/main_bonus.c _bonus/list_bonus.c _bonus/squish_sort_bonus.c $(PARSING_BONUS) $(OPS_BONUS) $(GET_NEXT_LINE_BONUS) _bonus/push_swap_bonus.h _bonus/get_next_line/get_next_line.h
	cc $(CFLAGS) _bonus/checker_bonus.c _bonus/helpers_bonus.c _bonus/main_bonus.c _bonus/squish_sort_bonus.c $(PARSING_BONUS) $(OPS_BONUS) $(GET_NEXT_LINE_BONUS) _bonus/list_bonus.c -o checker
clean:
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
fclean: clean
re: fclean all bonus