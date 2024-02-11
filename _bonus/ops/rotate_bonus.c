/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:21:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/11 15:29:04 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include <unistd.h>

void	rotate_a(t_list **stack_a, int mode)
{
	t_list	*last;
	t_list	*stack_a_next;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	last = *stack_a;
	stack_a_next = (*stack_a)->next;
	while (last->next)
		last = last->next;
	last->next = (*stack_a);
	(*stack_a)->next = NULL;
	(*stack_a) = stack_a_next;
	if (mode)
		write(STDOUT_FILENO, "ra\n", 3);
}

void	rotate_b(t_list **stack_b, int mode)
{
	t_list	*last;
	t_list	*stack_b_next;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	last = *stack_b;
	stack_b_next = (*stack_b)->next;
	while (last->next)
		last = last->next;
	last->next = (*stack_b);
	(*stack_b)->next = NULL;
	(*stack_b) = stack_b_next;
	if (mode)
		write(STDOUT_FILENO, "rb\n", 3);
}

void	rotate_ab(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
}
