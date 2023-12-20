/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 00:00:03 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/20 17:20:01 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
void	set_target_node_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*head_b;
	t_stack_node	*target_node;
	long			best_target;

	while (a)
	{
		best_target = -2147483649;
		head_b = b;
		while (head_b)
		{
			if (head_b->value < a->value
				&& head_b->value > best_target)
			{
				best_target = head_b->value;
				target_node = head_b;
			}
			head_b = head_b->next;
		}
		if (best_target == -2147483649)
			a->target = find_biggest(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

/*
** Take a stack and assign each node its push cost (in instruction)
*/
void	set_price_node_a(t_stack_node *a, t_stack_node *b)
{
	int	len_stack_a;
	int	len_stack_b;

	len_stack_a = size_stack(a);
	len_stack_b = size_stack(b);
	while (a)
	{
		a->push_price = a->current_pos;
		if (!(a->above_median))
			a->push_price = len_stack_a - (a->current_pos);
		if (a->target->above_median)
			a->push_price += a->target->current_pos;
		else if (!(a->target->above_median))
			a->push_price += len_stack_b - (a->target->current_pos);
		a = a->next;
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
void	init_stack_utils_a(t_stack_node **a, t_stack_node **b)
{
	set_position_node(a);
	set_position_node(b);
	set_target_node_a(*a, *b);
	set_price_node_a(*a, *b);
	set_cheapest_node(a);
}
