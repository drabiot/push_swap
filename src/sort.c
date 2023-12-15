/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:44:00 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/14 15:44:19 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack_node	*return_cheapest(t_stack_node **stack)
{
	t_stack_node	*head;
	
	if (!stack || !*stack)
		return (NULL);
	head = *stack;
	while (head)
	{
		if (head->cheapest)
			return (head);
		head = head->next;
	}
	return (NULL);
}

static void rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while (*a != cheap->target && *b != cheap)
		rotate_all(a, b);
	set_position_node(a);
	set_position_node(b);
}

static void r_r_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while (*a != cheap->target && *b != cheap)
		reverse_rotate_all(a, b);
	set_position_node(a);
	set_position_node(b);
}

void finish_rotation(t_stack_node **stack, t_stack_node *cheap, char name)
{
	while (*stack != cheap)
	{
		if (name == 'a')
		{
			if (cheap->above_median)
				rotate_a(stack);
			else
				reverse_rotate_a(stack);
		}
		else if (name == 'b')
		{
			if (cheap->above_median)
				rotate_b(stack);
			else
				reverse_rotate_b(stack);
		}
	}
}

static void	set_rotate_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;
	
	cheapest_node = return_cheapest(b);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		r_r_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target, 'a');
	push_a(a, b);
}

void	sort(t_stack_node **a, t_stack_node **b)
{
	int				len_stack;
	t_stack_node	*smallest;

	len_stack = size_stack(*a);
	if (len_stack == 5)
		little_sort(a, b);
	else
	{
		while (len_stack > 3)
		{
			push_b(b, a);
			len_stack--;
		}
	}
	while (*b)
	{
		init_stack_utils(a, b);
		set_rotate_node(a, b);
	}
	set_position_node(a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
	{
		while ((*a)->value != smallest->value)
			rotate_a(a);
	}
	else
	{
		while ((*a)->value != smallest->value)
			reverse_rotate_a(a);
	}
}
