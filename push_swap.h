/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:48:42 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/18 23:53:05 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				integer;
	struct s_list	*next;
	struct s_list	*last;
}					t_list;

void	verify(char **input);
void	exitf(void);
void	push(char **numlist, t_list **stack);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);

long	satoi(char *str);

t_list	*ft_lstnew(int integer);

#endif