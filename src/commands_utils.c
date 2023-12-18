/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:07:59 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/11 23:10:25 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Count the total number of nodes in a given stack
*/
int	size_stack(t_stack_node *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

/*
** Return the last node of the given stack
*/
t_stack_node	*last_node(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/*
** Add a new node in the front (tail) of a given stack
*/
void	add_front(t_stack_node **stack, t_stack_node *new)
{
	if (stack && new)
	{
		new->next = *stack;
		*stack = new;
	}
}

/*
** Add a new node in the back (head) of a given stack
*/
void	add_back(t_stack_node **stack, t_stack_node *new)
{
	t_stack_node	*buffer;

	if (!stack)
		return ;
	if (!*stack)
		*stack = new;
	else
	{
		buffer = last_node((*stack));
		buffer->next = new;
	}
}

/*
** Take a stack and set the cheapest node on the top of the stack
*/
void	finish_rotation(t_stack_node **stack,
		t_stack_node *cheapest,
		char stack_name)
{
	while (*stack != cheapest)
	{
		if (stack_name == 'a')
		{
			if (cheapest->above_median)
				rotate_a(stack);
			else
				reverse_rotate_a(stack);
		}
		else if (stack_name == 'b')
		{
			if (cheapest->above_median)
				rotate_b(stack);
			else
				reverse_rotate_b(stack);
		}
	}
}
