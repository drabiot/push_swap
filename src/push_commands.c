/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:24:02 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/12 18:24:04 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*node_to_push;
	t_stack_node	*current;

	if (!src || !*src)
		return ;
	if (!(*src)->next)
	{
		node_to_push = *src;
		*src = NULL;
		node_to_push->next = *dst;
		*dst = node_to_push;
	}
	else
	{
		current = *src;
		while (current->next->next)
			current = current->next;
		node_to_push = current->next;
		current->next = NULL;
		node_to_push->next = *dst;
		*dst = node_to_push;
	}
	
}

void	push_a(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
}

void	push_b(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
}

