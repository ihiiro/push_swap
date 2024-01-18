/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:49:16 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/18 23:52:56 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	if (argc == 1)
		exitf();
	stack_a = NULL;
	verify(argv + 1);
	push(argv + 1, &stack_a);
	ft_lstclear(&stack_a);
	return (EXIT_SUCCESS);
}
