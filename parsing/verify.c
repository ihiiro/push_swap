/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:01:55 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/02/11 15:31:30 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

static int	figure(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 || str[i] == '\0');
}

static int	integer(char *str)
{
	long	integer;

	integer = satoi(str);
	if (integer > INT_MAX || integer < INT_MIN)
		return (0);
	return (1);
}

static void	verify_category(char **input, int (*verifier)(char *))
{
	int	i;
	int	j;

	if (!verifier)
		return ;
	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			while (input[i][j] == 32)
				j++;
			if (!verifier(&input[i][j]))
				exitf();
			if (input[i][j] == '-' || input[i][j] == '+')
				j++;
			while (input[i][j] >= '0' && input[i][j] <= '9')
				j++;
			while (input[i][j] == 32)
				j++;
		}
		i++;
	}
}

void	verify(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i][0] == '\0')
			exitf();
		i++;
	}
	verify_category(input, figure);
	verify_category(input, integer);
}
