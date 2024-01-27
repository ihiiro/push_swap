/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:21:47 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/27 17:14:27 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_to_bottom(t_list **head, int span)
{
	while (span--)
		rotate_a(head, 1);
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
	t_list	*ptr;
	int		rot_max;
	int		rot;
	int		max;

	rot = 0;
	max = (*stack_b)->integer;
	ptr = *stack_b;
	rot_max = 0;
	while (ptr)
	{
		if (ptr->integer > max)
		{
			rot_max = rot;
			max = ptr->integer;
		}
		rot++;
		ptr = ptr->next;
	}
	// printf("rot_max=%d\n", rot_max);
	while (rot_max)
	{
		rotate_b(stack_b, 1);
		rot_max--;
	}
	push_a(stack_a, stack_b);
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
	// for (t_list *ptr = *stack_a; ptr; ptr = ptr->next)
	// 	printf("%d, ", ptr->integer);
}
