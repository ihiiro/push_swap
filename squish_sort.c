/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squish_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:21:47 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/06 17:12:51 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_min(t_list *stack_a, int index)
{
	t_list	*min;

	min = stack_a;
	while (min && min->index > -1)
		min = min->next;
	while (stack_a)
	{
		if (stack_a->index == -1)
		{
			if (stack_a->integer < min->integer)
				min = stack_a;
		}
		stack_a = stack_a->next;
	}
	min->index = index;
}

void	index_set(t_list *stack_a)
{
	int	index;
	int	size;

	index = 0;
	size = ft_lstsize(stack_a);
	while (index < size)
	{
		index_min(stack_a, index);
		index++;
	}
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	int	x;
	int	y;

	x = 0;
	y = 16;
	while (*stack_a)
	{
		if ((*stack_a)->index < y)
		{
			push_b(stack_a, stack_b);
			x++;
		}
		else if ((*stack_a)->index < x + y)
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b, 0);
			x++;
		}
		else
			push_b(stack_a, stack_b);
	}
}
