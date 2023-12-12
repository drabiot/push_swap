/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:44:18 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/12 16:44:22 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Shift down up elements of the given stack by 1
*/
static void	rotate(t_stack_node **stack)
{
	int				len_stack;
	t_stack_node	*head;
	t_stack_node	*last;
	t_stack_node	*end;

	len_stack = size_stack(*stack);
	if (!stack || !*stack || len_stack == 1)
		return ;
	head = *stack;
	end = *stack;
	while (end->next->next)
			end = end->next;
	last = last_node(*stack);
	add_front(stack, last);
	end->next = NULL;
}

/*
** Shift down up elements of stack a by 1
*/
void	rotate_a(t_stack_node **a)
{
	rotate(a);
}

/*
** Shift down up elements of stack b by 1
*/
void	rotate_b(t_stack_node **b)
{
	rotate(b);
}

/*
** Shift up all elements of the two stacks a & b by 1
*/
void	rotate_all(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
}
