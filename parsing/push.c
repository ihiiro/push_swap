/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:03:14 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/19 00:06:46 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_push(char **input, t_list **lst, int (*op)(char *, t_list **))
{
	int	i;
	int	j;

	if (!op)
		return ;
	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			while ((input[i][j] >= 9 && input[i][j] <= 13) || input[i][j] == 32)
				j++;
			if (!op(&input[i][j], lst))
				exitf();
			if (input[i][j] == '-' || input[i][j] == '+')
				j++;
			while (input[i][j] >= '0' && input[i][j] <= '9')
				j++;
			while ((input[i][j] >= 9 && input[i][j] <= 13) || input[i][j] == 32)
				j++;
		}
		i++;
	}
}

static int	uniq(int target, t_list *lst)
{
	while (lst)
	{
		if (target == lst->integer)
			return (0);
		lst = lst->next;
	}
	return (1);
}

static int	pusher(char *str, t_list **stack)
{
	int		integer;
	t_list	*ptr;

	ptr = *stack;
	integer = satoi(str);
	if (!ptr)
		ft_lstadd_back(stack, ft_lstnew(integer));
	else
	{
		if (!uniq(integer, *stack))
		{
			ft_lstclear(stack);
			return (0);
		}
		ft_lstadd_back(stack, ft_lstnew(integer));
	}
	return (1);
}

void	push(char **numlist, t_list **stack)
{
	check_push(numlist, stack, pusher);
}
