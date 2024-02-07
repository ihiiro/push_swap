/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:49:16 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/07 20:52:26 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
	if (sorted(stack_a))
	{
		ft_lstclear(&stack_a);
		exit(EXIT_SUCCESS);
	}
	if (ft_lstsize(stack_a) < 6)
	{
		small_sort(&stack_a, &stack_b);
		exit(EXIT_SUCCESS);
	}
	index_set(stack_a);
	push_to_b(&stack_a, &stack_b);
	while (stack_b)
		push_max_to_a(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (EXIT_SUCCESS);
}
