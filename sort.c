/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:21:47 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/27 16:23:21 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_to_bottom(t_list **head, int span)
{
	while (span--)
		rotate_a(head, 0);
}
#include <stdio.h>
static int	sorted(t_list *head)
{
	while (head && head->next)
	{
		if (head->integer > head->next->integer)
			return (0);
		head = head->next;
	}
	return (1);
}

#include <stdlib.h>
static int	push_top_2_lists_to_b(t_list **stack_a, t_list **stack_b)
{
	while (*stack_a && (*stack_a)->next && (*stack_a)->integer < (*stack_a)->next->integer)
		push_b(stack_a, stack_b);
	if (*stack_a)
		push_b(stack_a, stack_b);
	while (*stack_a && (*stack_a)->next && (*stack_a)->integer < (*stack_a)->next->integer)
		push_b(stack_a, stack_b);
	if (*stack_a)
		push_b(stack_a, stack_b);
	return (ft_lstsize(*stack_b));
}

static void	push_b_max_to_a(t_list **stack_a, t_list **stack_b)
{
	(void)stack_a;
	int	max;
	int	rot;
	int	size;

	rot = 0;
	max = (*stack_b)->integer;
	size = ft_lstsize(*stack_b);
	// while (rot < size - 1)
	// {
	// 	if ((*stack_b)->integer > max)
	// 		max = (*stack_b)->integer;
	// 	rot++;
	// 	// rotate_b(stack_b, 1);
	// 	for (t_list *ptr = *stack_b; ptr; ptr = ptr->next)
	// 		printf("%d, ", ptr->integer);
	// 	printf("\n");
	// }
	// rotate_b(stack_b, 1);
	printf("%d", (*stack_b)->last->integer);
	// for (t_list *ptr = *stack_b; ptr; ptr = ptr->next)
	// 		printf("%d, ", ptr->integer);
	// printf("%d", max); 
	exit(0);
}

void	merge_sort(t_list **stack_a, t_list **stack_b)
{
	int	list_size;

	while (!sorted(*stack_a) || ft_lstsize(*stack_b))
	{
		list_size = push_top_2_lists_to_b(stack_a, stack_b);
		while (ft_lstsize(*stack_b))
			push_b_max_to_a(stack_a, stack_b);
		if (!(sorted(*stack_a) && !ft_lstsize(*stack_b)))
			pop_to_bottom(stack_a, list_size);
	}
}
