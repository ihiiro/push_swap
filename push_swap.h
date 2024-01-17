/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:48:42 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/17 19:58:13 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


typedef struct s_list
{
	int				integer;
	struct s_list	*next;
}					t_list;

void	verify_numlist(char **input);
void	exitf(void);

#endif