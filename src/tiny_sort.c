/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:53:54 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/13 15:34:11 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

static void	sort_tiny_stack(t_stack_node **stack, int pos)
{
 	if (pos == 1)
		reverse_rotate_a(stack);
	else if (pos == 2)
		rotate_a(stack);
	if (!is_sorted(*stack))
		swap_a(stack);
}
void	tiny_sort(t_stack_node **stack)
{
	int				data;
	int				len_stack;
	int				pos;
	int				final_pos; 
	t_stack_node	*head;

	if (!stack || !*stack)
		return ;
	head = *stack;
	data = head->value;
	len_stack = size_stack(*stack);
	pos = 0;
	final_pos = 0;
	if (is_sorted(*stack) || len_stack > 3)
		return ;
	while (head->next)
	{
		head = head->next;
		pos++;
		if (head->value > data)
			final_pos = pos;
	}
	sort_tiny_stack(stack, final_pos);
}
