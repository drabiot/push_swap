/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:22:23 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/11 18:34:02 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *stack_a)
{
	int	tmp;

	tmp = 0;
	if (stack_a[0] && stack_a[1])
	{
		tmp = stack_a[0];
		stack_a[0] = stack_a[1];
		stack_a[1] = tmp;
	}
}

void	swap_b(int *stack_b)
{
	int tmp;

	tmp = 0;
	if (stack_b[0] && stack_b[1])
	{
		tmp = stack_b[0];
		stack_b[0] = stack_b[1];
		stack_b[1] = tmp;
	}
}

void	swap_all_stack(int *stack_a, int *stack_b)
{
	if ((stack_a[0] && stack_a[1]) && (stack_b[0] && stack_b[1]))
	{
		swap_a(stack_a);
		swap_b(stack_b);
	}
}
