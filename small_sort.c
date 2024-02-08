/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:37:01 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/08 16:27:29 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	sort_3(t_list **stack_a)
{
	int	max;

	if ((*stack_a)->integer > (*stack_a)->next->integer)
		max = (*stack_a)->integer;
	else
		max = (*stack_a)->next->integer;
	if ((*stack_a)->next->next->integer > max)
		max = (*stack_a)->next->next->integer;
	while (max != (*stack_a)->next->next->integer)
		rotate_a(stack_a, 1);
	if ((*stack_a)->integer > (*stack_a)->next->integer)
		swap_a(stack_a, 1);
}

static void	sort_4(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;
	int		min;

	min = (*stack_a)->integer;
	ptr = *stack_a;
	while (ptr)
	{
		if (ptr->integer < min)
			min = ptr->integer;
		ptr = ptr->next;
	}
	while ((*stack_a)->integer != min)
		rrotate_a(stack_a, 1);
	push_b(stack_a, stack_b);
	sort_3(stack_a);
	push_a(stack_a, stack_b);
}

static void	sort_5(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;
	int		min;

	min = (*stack_a)->integer;
	ptr = *stack_a;
	while (ptr)
	{
		if (ptr->integer < min)
			min = ptr->integer;
		ptr = ptr->next;
	}
	while ((*stack_a)->integer != min)
		rrotate_a(stack_a, 1);
	push_b(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	small_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		swap_a(stack_a, 1);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
