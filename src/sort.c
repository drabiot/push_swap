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

#include "../include/push_swap.h"

/*
** Rotate the two given stack until one of the cheapest node
** is on top of the stack 
*/
void	rotate_both(t_stack_node **a,
			t_stack_node **b,
			t_stack_node *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rotate_all(a, b);
	set_position_node(a);
	set_position_node(b);
}

/*
** Reverse rotate the two given stack until one of the cheapest
** node is on top of the stack 
*/
void	reverse_rotate_both(t_stack_node **a,
			t_stack_node **b,
			t_stack_node *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		reverse_rotate_all(a, b);
	set_position_node(a);
	set_position_node(b);
}

/*
** Rotate or reverse rotate the two given stack until the cheapest node
** or its target are on the top of the stack
*/
void	set_rotate_node(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(b);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target, 'a');
	push_a(a, b);
}

/*
** Set the smallest value on the top of the given stack
*/
static void	smallest_on_top(t_stack_node **a, t_stack_node *smallest)
{
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

/*
** Sort the given stack a and put the smallest value on top
*/
void	sort(t_stack_node **a, t_stack_node **b)
{
	int				len_stack_a;
	t_stack_node	*smallest;

	len_stack_a = size_stack(*a);
	while (len_stack_a > 3)
	{
		push_b(b, a);
		len_stack_a--;
	}
	tiny_sort(a);
	while (*b)
	{
		init_stack_utils(a, b);
		set_rotate_node(a, b);
	}
	set_position_node(a);
	smallest = find_smallest(a);
	smallest_on_top(a, smallest);
}
