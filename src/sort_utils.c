/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 00:00:03 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/18 00:00:05 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Take a stack and assign each node its position
*/
void	set_position_node(t_stack_node **stack)
{
	t_stack_node	*head;
	int				median;
	int				pos;

	pos = 0;
	if (!stack || !*stack)
		return ;
	head = *stack;
	median = size_stack(head) / 2;
	while (head)
	{
		head->current_pos = pos;
		if (pos <= median)
			head->above_median = 1;
		else
			head->above_median = 0;
		head = head->next;
		pos++;
	}
}

/*
** Take a stack and assign each node its target node.
** The nodes in the stack should point to the smallest
** number greater than themselves in the stack b.
** If there is no greater number, point to the smallest one
*/
void	set_target_node(t_stack_node **a, t_stack_node *b)
{
	t_stack_node	*head_a;
	t_stack_node	*target_node;
	long			best_target;

	while (b)
	{
		best_target = 2147483648;
		head_a = *a;
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
** Take a stack and assign each node its push cost (in instruction)
*/
void	set_price_node(t_stack_node **a, t_stack_node *b)
{
	int	len_stack_a;
	int	len_stack_b;

	len_stack_a = size_stack(*a);
	len_stack_b = size_stack(b);
	while (b)
	{
		b->push_price = b->current_pos;
		if (!(b->above_median))
			b->push_price = len_stack_b - (b->current_pos);
		if (b->target->above_median)
			b->push_price += b->target->current_pos;
		else if (!(b->target->above_median))
			b->push_price += len_stack_a - (b->target->current_pos);
		b = b->next;
	}
}

/*
** Take a stack and check if it is the most economical
** to push by examining its cost
*/
void	set_cheapest_node(t_stack_node **stack)
{
	t_stack_node	*head;
	t_stack_node	*cheapest_node;
	long			cheapest;

	if (!stack || !*stack)
		return ;
	cheapest = 2147483648;
	head = *stack;
	while (head)
	{
		if (head->push_price < cheapest)
		{
			cheapest = head->push_price;
			cheapest_node = head;
		}
		head = head->next;
	}
	cheapest_node->cheapest = 1;
}

/*
** Initialize all the nodes in the given stack
*/
void	init_stack_utils(t_stack_node **a, t_stack_node **b)
{
	set_position_node(a);
	set_position_node(b);
	set_target_node(a, *b);
	set_price_node(a, *b);
	set_cheapest_node(b);
}
