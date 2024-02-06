/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:49:16 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/06 19:37:58 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		exit(EXIT_FAILURE);
	stack_a = NULL;
	stack_b = NULL;
	verify(argv + 1);
	push(argv + 1, &stack_a);
	index_set(stack_a);
	push_to_b(&stack_a, &stack_b);
	while (stack_b)
		push_max_to_a(&stack_a, &stack_b);
	return (EXIT_SUCCESS);
}
