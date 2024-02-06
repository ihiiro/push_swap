# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 17:42:48 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/02/06 16:56:48 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
PARSING = parsing/verify.c parsing/exitf.c parsing/push.c parsing/satoi.c
OPS = ops/swap.c ops/push.c ops/rotate.c ops/rrotate.c
PUSH_SWAP_TOOLS = push_swap_tools/push_swap_tools_0.c

all: $(NAME)
$(NAME): main.c list.c squish_sort.c $(PARSING) $(OPS) $(PUSH_SWAP_TOOLS) push_swap.h
	cc $(CFLAGS) main.c squish_sort.c $(PARSING) $(OPS) $(PUSH_SWAP_TOOLS) list.c -o $@
clean:
	rm -f $(NAME)
fclean: clean
re: fclean all