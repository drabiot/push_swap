/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:53:54 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/17 22:14:13 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
** Return the smallest node's value in the given stack
*/
t_stack_node	*find_smallest(t_stack_node **stack)
{
	t_stack_node	*smallest_node;
	t_stack_node	*head;
	long			smallest;

	if (!stack || !*stack)
		return (NULL);
	head = *stack;
	smallest = 2147483648;
	while (head)
	{
		if (head->value < smallest)
		{
			smallest = head->value;
			smallest_node = head;
		}
		head = head->next;
	}
	return (smallest_node);
}

/*
** Return the biggest node's value in the given stack
*/
t_stack_node	*find_biggest(t_stack_node **stack)
{
	t_stack_node	*biggest_node;
	t_stack_node	*head;
	long			biggest;

	if (!stack || !*stack)
		return (NULL);
	head = *stack;
	biggest = -2147483649;
	while (head)
	{
		if (head->value > biggest)
		{
			biggest = head->value;
			biggest_node = head;
		}
		head = head->next;
	}
	return (biggest_node);
}

/*
** Check if the stack is correctly sorted
*/
int	is_sorted(t_stack_node *stack)
{
	int				data;
	t_stack_node	*head;

	if (!stack)
		return (2);
	head = stack;
	data = head->value;
	while (head->next)
	{
		head = head->next;
		if (head->value < data)
			return (0);
		data = head->value;
	}
	return (1);
}

/*
** Sort a stack of 3 maximum elements
*/
void	tiny_sort(t_stack_node **stack)
{
	t_stack_node	*biggest_node;
	int				len_stack;

	if (!stack || !*stack)
		return ;
	len_stack = size_stack(*stack);
	biggest_node = find_biggest(stack);
	if (!is_sorted(*stack))
	{
		if (len_stack == 2)
			swap_a(stack);
		else if (len_stack == 3)
		{
			if ((*stack)->value == biggest_node->value)
				rotate_a(stack);
			else if ((*stack)->next->value == biggest_node->value)
				reverse_rotate_a(stack);
			if (!is_sorted(*stack))
				swap_a(stack);
		}
	}
}

/*
** Sort a stack of 4 or 5 elements
*/
void	little_sort(t_stack_node **a, t_stack_node **b)
{
	while (size_stack(*a) > 3)
	{
		init_stack_utils(a, b);
		finish_rotation(a, find_smallest(a), 'a');
		push_b(b, a);
	}
}
