/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:21:46 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/27 16:19:59 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void	rotate_a(t_list **stack_a, int mode)
{
	(*stack_a)->last->next = (*stack_a);
	(*stack_a)->last = (*stack_a)->last->next;
	(*stack_a)->next->last = (*stack_a)->last;
	(*stack_a) = (*stack_a)->next;
	(*stack_a)->last->next = NULL;
	if (mode)
		write(STDOUT_FILENO, "ra\n", 3);
}

void	rotate_b(t_list **stack_b, int mode)
{
	(*stack_b)->last->next = (*stack_b);
	(*stack_b)->last = (*stack_b)->last->next;
	(*stack_b)->next->last = (*stack_b)->last;
	(*stack_b) = (*stack_b)->next;
	(*stack_b)->last->next = NULL;
	if (mode)
		write(STDOUT_FILENO, "rb\n", 3);
}

void	rotate_ab(t_list **stack_a, t_list **stack_b)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	write(STDOUT_FILENO, "rr\n", 3);
}
