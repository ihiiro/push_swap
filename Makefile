# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 17:42:48 by yel-yaqi          #+#    #+#              #
#    Updated: 2024/01/17 20:04:36 by yel-yaqi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
PUSH_SWAP_TOOLS = verify.c exitf.c push.c

all: $(NAME)
$(NAME): main.c $(PUSH_SWAP_TOOLS) push_swap.h
	cc $(CFLAGS) main.c $(PUSH_SWAP_TOOLS) -o $@
clean:
	rm -f $(NAME)
fclean: clean
re: fclean all