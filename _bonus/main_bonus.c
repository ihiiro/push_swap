/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:49:16 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/08 16:32:11 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*ops;

	if (argc == 1)
		exit(EXIT_FAILURE);
	stack_a = NULL;
	stack_b = NULL;
	ops = NULL;
	verify(argv + 1);
	push(argv + 1, &stack_a);
	index_set(stack_a);
	store_ops(&ops);
	exec_ops(ops, &stack_a, &stack_b);
	if (!stack_b && sorted(stack_a))
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	ft_lstclear(&stack_a);
	ft_lstclear(&ops);
	return (EXIT_SUCCESS);
}
