/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:03:19 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/12 16:18:28 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Swap the first two elements of the given stack
*/
static void	swap(t_stack_node **stack)
{
	int				len_stack;
	int				tmp;
	t_stack_node	*head;
	t_stack_node	*second;

	len_stack = size_stack(*stack);
	if (!stack || !*stack || len_stack == 1)
		return ;
	head = *stack;
	second = NULL;
	while (head->next)
	{
		second = head;
		head = head->next;
	}
	tmp = second->value;
	second->value = head->value;
	head->value = tmp;
}

/*
** Swap the first two elements of stack a
*/
void	swap_a(t_stack_node **a)
{
	swap(a);
}

/*
** Swap the first two elements of stack b
*/
void	swap_b(t_stack_node **b)
{
	swap(b);
}

/*
** Swap the first two elements of the two stacks a & b
*/
void	swap_all(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
}
