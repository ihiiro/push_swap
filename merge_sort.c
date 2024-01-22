/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:38:49 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/22 15:01:58 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	merge_sort(t_list **head)
{
	
}