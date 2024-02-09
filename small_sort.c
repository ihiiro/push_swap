/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:37:01 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/09 10:56:18 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	rot_n(t_list **stack_a, int n, int rot)
{
	if (rot == 0)
		while (n--)
			rotate_a(stack_a, 1);
	else
		while (n--)
			rrotate_a(stack_a, 1);
}

static void	sort_3(t_list **stack_a)
{
	int	max;

	if ((*stack_a)->integer > (*stack_a)->next->integer)
		max = (*stack_a)->integer;
	else
		max = (*stack_a)->next->integer;
	if ((*stack_a)->next->next->integer > max)
		max = (*stack_a)->next->next->integer;
	if ((*stack_a)->integer == max)
		rot_n(stack_a, 1, 0);
	else if ((*stack_a)->next->integer == max)
		rot_n(stack_a, 1, 1);
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
	if ((*stack_a)->next->integer == min)
		rot_n(stack_a, 1, 0);
	else if ((*stack_a)->next->next->integer == min)
		rot_n(stack_a, 2, 0);
	else if ((*stack_a)->next->next->next->integer == min)
		rot_n(stack_a, 1, 1);
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
	if ((*stack_a)->next->integer == min)
		rot_n(stack_a, 1, 0);
	else if ((*stack_a)->next->next->integer == min)
		rot_n(stack_a, 2, 0);
	else if ((*stack_a)->next->next->next->integer == min)
		rot_n(stack_a, 2, 1);
	else if ((*stack_a)->next->next->next->next->integer == min)
		rot_n(stack_a, 1, 1);
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
