/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:48:15 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/07 11:59:50 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "get_next_line/get_next_line.h"
#include <unistd.h>

static int	verify_op(char *buf)
{
	if (!strictcmp(buf, "sa\n"))
		return (0);
	if (!strictcmp(buf, "sb\n"))
		return (1);
	if (!strictcmp(buf, "ss\n"))
		return (2);
	if (!strictcmp(buf, "pa\n"))
		return (3);
	if (!strictcmp(buf, "pb\n"))
		return (4);
	if (!strictcmp(buf, "ra\n"))
		return (5);
	if (!strictcmp(buf, "rb\n"))
		return (6);
	if (!strictcmp(buf, "rr\n"))
		return (7);
	if (!strictcmp(buf, "rra\n"))
		return (8);
	if (!strictcmp(buf, "rrb\n"))
		return (9);
	if (!strictcmp(buf, "rrr\n"))
		return (10);
	else
		return (-1);
}

void	store_ops(t_list **ops)
{
	char	*op;
	int		id;

	while (1)
	{
		op = get_next_line(STDIN_FILENO);
		if (!op)
			break ;
		id = verify_op(op);
		if (id == -1)
		{
			free(op);
			ft_lstclear(ops);
			exitf();
		}
		ft_lstadd_back(ops, ft_lstnew(id));
		free(op);
	}
}

static void	exec_op(int id, t_list **stack_a, t_list **stack_b)
{
	if (id == 0)
		swap_a(stack_a, 0);
	if (id == 1)
		swap_b(stack_b, 0);
	if (id == 2)
		swap_ab(stack_a, stack_b);
	if (id == 3)
		push_a(stack_a, stack_b);
	if (id == 4)
		push_b(stack_a, stack_b);
	if (id == 5)
		rotate_a(stack_a, 0);
	if (id == 6)
		rotate_b(stack_b, 0);
	if (id == 7)
		rotate_ab(stack_a, stack_b);
	if (id == 8)
		rrotate_a(stack_a, 0);
	if (id == 9)
		rrotate_b(stack_b, 0);
	if (id == 10)
		rrotate_ab(stack_a, stack_b);
}

void	exec_ops(t_list *ops, t_list **stack_a, t_list **stack_b)
{
	while (ops)
	{
		exec_op(ops->integer, stack_a, stack_b);
		ops = ops->next;
	}
}
