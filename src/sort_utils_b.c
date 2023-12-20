/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 00:00:03 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/20 17:21:18 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Take a stack and assign each node its target node.
** The nodes in the stack should point to the smallest
** number greater than themselves in the stack b.
** If there is no greater number, point to the smallest one
*/
void	set_target_node_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*head_a;
	t_stack_node	*target_node;
	long			best_target;

	while (b)
	{
		best_target = 2147483648;
		head_a = a;
		while (head_a)
		{
			if (head_a->value > b->value
				&& head_a->value < best_target)
			{
				best_target = head_a->value;
				target_node = head_a;
			}
			head_a = head_a->next;
		}
		if (best_target == 2147483648)
			b->target = find_smallest(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

/*
** Initialize all the nodes in the given stack
*/
void	init_stack_utils_b(t_stack_node **a, t_stack_node **b)
{
	set_position_node(a);
	set_position_node(b);
	set_target_node_b(*a, *b);
}
