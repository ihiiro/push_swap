/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:48:42 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/27 16:41:53 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list
{
	int				integer;
	struct s_list	*next;
}					t_list;

void	verify(char **input);
void	exitf(void);
void	push(char **numlist, t_list **stack);

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);

void	swap_a(t_list **stack_a, int mode);
void	swap_b(t_list **stack_b, int mode);
void	swap_ab(t_list **stack_a, t_list **stack_b);

void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_a, t_list **stack_b);

void	rotate_a(t_list **stack_a, int mode);
void	rotate_b(t_list **stack_b, int mode);
void	rotate_ab(t_list **stack_a, t_list **stack_b);

void	rrotate_a(t_list **stack_a, int mode);
void	rrotate_b(t_list **stack_b, int mode);
void	rrotate_ab(t_list **stack_a, t_list **stack_b);

void	pop_to_bottom(t_list **seq_start, int seq_span);
void	merge_sort(t_list **stack_a, t_list **stack_b);

long	satoi(char *str);

t_list	*ft_lstnew(int integer);

int		ft_lstsize(t_list *lst);

int		sublist_len(t_list *ptr);

#endif