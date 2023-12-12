/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:04:04 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/12 17:04:08 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	int				len_stack;
	
	len_stack = size_stack(*stack);
	if (!stack || !*stack || len_stack == 1)
		return ;
	while ((len_stack) - 1 > 0)
	{
		rotate(stack);
		len_stack--;
	}
}

void	reverse_rotate_a(t_stack_node **a)
{
	reverse_rotate(a);
}

void	reverse_rotate_b(t_stack_node **b)
{
	reverse_rotate(b);
}

void	reverse_rotate_all(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
