/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:49:16 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/06 15:59:50 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

#include <stdio.h>
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
	//
	while (ft_lstsize(stack_a))
	{
		push_b(&stack_a, &stack_b);
		rotate_b(&stack_b, 0);
	}
	rotate_b(&stack_b, 0);
	printf("size_b=%d\n\n", ft_lstsize(stack_b));
	while (ft_lstsize(stack_b))
		push_a(&stack_a, &stack_b);
	printf("a=");
	for (t_list *ptr = stack_a; ptr; ptr = ptr->next)
		printf("%d, ", ptr->integer);
	printf("\nb=");
	for (t_list *ptr = stack_b; ptr; ptr = ptr->next)
		printf("%d, ", ptr->integer);
	// 
	ft_lstclear(&stack_a);
	return (EXIT_SUCCESS);
}
