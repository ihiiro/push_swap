/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:49:16 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/06 17:10:27 by yel-yaqi         ###   ########.fr       */
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
	index_set(stack_a);
	push_to_b(&stack_a, &stack_b);
	for (t_list *ptr = stack_b; ptr; ptr = ptr->next)
		printf("%d, ", ptr->integer);
	// 
	ft_lstclear(&stack_a);
	return (EXIT_SUCCESS);
}
