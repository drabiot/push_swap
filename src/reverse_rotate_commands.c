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

/*
** Shift down all elements of the given stack by 1
*/
static void	reverse_rotate(t_stack_node **stack)
{
	int				len_stack;
	t_stack_node	*head;
	t_stack_node	*end;
	
	len_stack = size_stack(*stack);
	if (!stack || !*stack || len_stack == 1)
		return ;
	head = *stack;
	end = *stack;
	add_back(stack, head);
	*stack = (*stack)->next;
	end->next = NULL;
}

/*
** Shift down all elements of stack a by 1
*/
void	reverse_rotate_a(t_stack_node **a)
{
	reverse_rotate(a);
}

/*
** Shift down all elements of stack b by 1
*/
void	reverse_rotate_b(t_stack_node **b)
{
	reverse_rotate(b);
}

/*
** Shift down all elements of the two stacks a & b by 1
*/
void	reverse_rotate_all(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
