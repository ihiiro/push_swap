/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:19:15 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/19 15:13:34 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <unistd.h>

void	swap_a(t_list *stack_a, int mode)
{
	int	tmp;

	if (ft_lstsize(stack_a) > 1)
	{
		tmp = stack_a->integer;
		stack_a->integer = stack_a->next->integer;
		stack_a->next->integer = tmp;
	}
	if (mode)
		write(STDOUT_FILENO, "sa\n", 3);
}

void	swap_b(t_list *stack_b, int mode)
{
	int	tmp;

	if (ft_lstsize(stack_b) > 1)
	{
		tmp = stack_b->integer;
		stack_b->integer = stack_b->next->integer;
		stack_b->next->integer = tmp;
	}
	if (mode)
		write(STDOUT_FILENO, "sb\n", 3);
}

void	swap_ab(t_list *stack_a, t_list *stack_b)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	write(STDOUT_FILENO, "ss\n", 3);
}
