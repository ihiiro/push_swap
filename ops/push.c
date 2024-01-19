/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:01:52 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/19 15:19:13 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void	push_a(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_b))
		ft_lstadd_front(stack_a, *stack_b);
	write(STDOUT_FILENO, "pa\n", 3);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a))
		ft_lstadd_front(stack_b, *stack_a);
	write(STDOUT_FILENO, "pb\n", 3);
}
