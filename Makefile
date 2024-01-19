# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 17:42:48 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/01/19 15:18:19 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
PARSING = parsing/verify.c parsing/exitf.c parsing/push.c parsing/satoi.c
OPS = ops/swap.c ops/push.c

all: $(NAME)
$(NAME): main.c $(PARSING) $(OPS) push_swap.h
	cc $(CFLAGS) main.c $(PARSING) $(OPS) list.c -o $@
clean:
	rm -f $(NAME)
fclean: clean
re: fclean all