/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squish_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:21:47 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/07 12:04:26 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_list *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->integer > stack_a->next->integer)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

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
	if (ft_lstsize(*stack_a) >= 500)
		y = 32;
	while (*stack_a)
	{
		if ((*stack_a)->index <= x)
		{
			push_b(stack_a, stack_b);
			x++;
		}
		else if ((*stack_a)->index < x + y)
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b, 1);
			x++;
		}
		else
			rotate_a(stack_a, 1);
	}
}

void	push_max_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*ptr;
	int		max_index;
	int		d;

	max_index = ft_lstsize(*stack_b) - 1;
	ptr = *stack_b;
	d = 0;
	while (ptr)
	{
		if (ptr->index == max_index)
			break ;
		ptr = ptr->next;
		d++;
	}
	if (d > (max_index) / 2)
	{
		d = (max_index + 1) - d;
		while (d--)
			rrotate_b(stack_b, 1);
	}
	else
		while (d--)
			rotate_b(stack_b, 1);
	push_a(stack_a, stack_b);
}
