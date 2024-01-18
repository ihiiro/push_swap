/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:19:37 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/19 00:18:38 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 0;
	while (lst)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		ptr = (*lst)->next;
		free(*lst);
		*lst = ptr;
	}
	*lst = NULL;
}

t_list	*ft_lstnew(int integer)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->integer = integer;
	node->next = NULL;
	node->last = node;
	return (node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		ft_lstadd_front(lst, new);
		return ;
	}
	(*lst)->last->next = new;
	(*lst)->last = new;
}
