/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:59:45 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/11 15:30:18 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void	rrotate_a(t_list **stack_a, int mode)
{
	t_list	*ptr;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	ptr = (*stack_a);
	while (ptr->next->next)
		ptr = ptr->next;
	ptr->next->next = (*stack_a);
	(*stack_a) = ptr->next;
	ptr->next = NULL;
	if (mode)
		write(STDOUT_FILENO, "rra\n", 4);
}

void	rrotate_b(t_list **stack_b, int mode)
{
	t_list	*ptr;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	ptr = (*stack_b);
	while (ptr->next->next)
		ptr = ptr->next;
	ptr->next->next = (*stack_b);
	(*stack_b) = ptr->next;
	ptr->next = NULL;
	if (mode)
		write(STDOUT_FILENO, "rrb\n", 4);
}

void	rrotate_ab(t_list **stack_a, t_list **stack_b)
{
	rrotate_a(stack_a, 0);
	rrotate_b(stack_b, 0);
	write(STDOUT_FILENO, "rrr\n", 4);
}
