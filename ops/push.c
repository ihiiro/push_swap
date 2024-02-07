/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:01:52 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/07 13:29:13 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*stack_b_next;

	if (!*stack_b)
	{
		write(STDOUT_FILENO, "pa\n", 3);
		return ;
	}
	stack_b_next = (*stack_b)->next;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = stack_b_next;
	write(STDOUT_FILENO, "pa\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*stack_a_next;

	if (!*stack_a)
	{
		write(STDOUT_FILENO, "pb\n", 3);
		return ;
	}
	stack_a_next = (*stack_a)->next;
	ft_lstadd_front(stack_b, *stack_a);
	*stack_a = stack_a_next;
	write(STDOUT_FILENO, "pb\n", 3);
}
