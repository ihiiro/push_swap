/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:19:15 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/15 18:31:31 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include <unistd.h>

void	swap_a(t_list **stack_a, int mode)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_a) < 2)
	{
		if (mode)
			write(STDOUT_FILENO, "sa\n", 3);
		return ;
	}
	tmp = *stack_a;
	(*stack_a) = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	if (mode)
		write(STDOUT_FILENO, "sa\n", 3);
}

void	swap_b(t_list **stack_b, int mode)
{
	t_list	*tmp;

	if (ft_lstsize(*stack_b) < 2)
	{
		if (mode)
			write(STDOUT_FILENO, "sb\n", 3);
		return ;
	}
	tmp = *stack_b;
	(*stack_b) = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	if (mode)
		write(STDOUT_FILENO, "sb\n", 3);
}

void	swap_ab(t_list **stack_a, t_list **stack_b)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
}
