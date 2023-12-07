/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:29:04 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/07 19:34:21 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *arg)
{
	int	i;

	i = 0;
	if (!(arg[i] == '+' || arg[i] == '-' || (arg[i] >= '0' && arg[i] <= '9')))
		return (1);
	if ((arg[i] == '+' || arg[i] == '-') 
		&& !(arg[i + 1] >= '0' && arg[i + 1] <= '9'))
		return (1);
	i++;
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	error_repetition(int *stack, int nb)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] == nb)
			return (1);
		i++;
	}
	return (0);
}
