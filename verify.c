/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-yaqi <yel-yaqi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:01:55 by yel-yaqi          #+#    #+#             */
/*   Updated: 2024/01/17 19:58:18 by yel-yaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	verify_numlist(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			while ((input[i][j] >= 9 && input[i][j] <= 13) || input[i][j] == 32)
				j++;
			if (!figure(&input[i][j]))
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
