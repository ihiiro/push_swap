/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:21:47 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/26 20:18:33 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_to_bottom(t_list **head, int span)
{
	while (span--)
		rotate_a(head, 0);
}
#include <stdio.h>
static int	sorted(t_list *head)
{
	while (head && head->next)
	{
		if (head->integer > head->next->integer)
			return (0);
		head = head->next;
	}
	return (1);
}

// static void	get_sublists(t_list *head, t_list **list0, t_list **list1)
// {
// 	*list0 = head;
// 	*list1 = head;
// 	while (*list1 && (*list1)->next && (*list1)->integer < (*list1)->next->integer)
// 		*list1 = (*list1)->next;
// 	if (*list1 && (*list1)->next)
// 		*list1 = (*list1)->next;
// }

#include <stdlib.h>
static void	merge(t_list **head, t_list **stack_b)
{
	int	i;

	i = 0;
	push_b(head, stack_b);
	for (t_list *ptr = *stack_b; ptr; ptr = ptr->next)
		printf("%d, ", ptr->integer);
	printf("\n");
	exit(0);
}

void	merge_sort(t_list **head, t_list **stack_b)
{
	// t_list	*list0;
	// t_list	*list1;

	while (!sorted(*head))
	{
		// get_sublists(*head, &list0, &list1);
		// if (list0 && list1 && list0->next == list1)
		// {
		// 	if (list0->integer > list1->integer)
		// 		swap_a(head, 0);
		// 	pop_to_bottom(head, 2);
		// }
		// else
		merge(head, stack_b);
	}
	for (t_list *ptr = *head; ptr; ptr = ptr->next)
		printf("%d, ", ptr->integer);
}

	// // printf("%d %d\n", list0->integer, list1->integer);
	// // printf("%d %d", (*head)->integer, (*head)->next->integer);
	// for (t_list *ptr = *head; ptr; ptr = ptr->next)
	// 	printf("%d, ", ptr->integer);