/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:44:18 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/12 16:44:22 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	int				len_stack;
	t_stack_node	*head;
	t_stack_node	*last;

	len_stack = size_stack(*stack);
	if (!stack || !*stack || len_stack == 1)
		return ;
	head = *stack;
	last = NULL;
	while (head->next)
	{
		last = head;
		head = head->next;
	}
	last->next = head->next;
	head->next = *stack;
	*stack = head;
}

void	rotate_a(t_stack_node **a)
{
	rotate(a);
}

void	rotate_b(t_stack_node **b)
{
	rotate(b);
}

void	rotate_all(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
}
