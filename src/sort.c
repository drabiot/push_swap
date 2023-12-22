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
** Rotate or reverse rotate the two given stack until the cheapest node
** or its target are on the top of the stack
*/
void	set_rotate_node_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(b, a, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		reverse_rotate_both(b, a, cheapest_node);
	finish_rotation(a, cheapest_node, 'a');
	finish_rotation(b, cheapest_node->target, 'b');
	push_b(b, a);
}

/*
** Rotate or reverse rotate the two given stack until the cheapest node
** or its target are on the top of the stack
*/
void	set_rotate_node_b(t_stack_node **a, t_stack_node **b)
{
	finish_rotation(a, (*b)->target, 'a');
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

static void	flush_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;

	smallest = NULL;
	while (*b)
	{
		init_stack_utils_b(a, b);
		set_rotate_node_b(a, b);
	}
	set_position_node(a);
	smallest = find_smallest(*a);
	smallest_on_top(a, smallest);
}

/*
** Sort the given stack a and put the smallest value on top
*/
void	sort(t_stack_node **a, t_stack_node **b)
{
	int				len_stack_a;
	int				push;

	push = 0;
	len_stack_a = size_stack(*a);
	while (len_stack_a > 3 && !is_sorted(*a) && push < 2)
	{
		push_b(b, a);
		len_stack_a--;
		push++;
	}
	while (len_stack_a > 3 && !is_sorted(*a))
	{
		init_stack_utils_a(a, b);
		set_rotate_node_a(a, b);
		len_stack_a--;
	}
	tiny_sort(a);
	flush_a_to_b(a, b);
}
