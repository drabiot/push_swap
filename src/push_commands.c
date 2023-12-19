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

#include "../include/push_swap.h"

/*
** Take the first element at the top of a given stack &
** put it at the top of an other given stack
*/
static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*node_to_push;

	if (!src || !*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	node_to_push->next = *dst;
	*dst = node_to_push;
}

/*
** Take the first element of the stack a & put it on top
** of stack b
*/
void	push_a(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write (1, "pa\n", 3);
}

/*
** Take the first element of the stack b & put it on top
** of stack a
*/
void	push_b(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	write (1, "pb\n", 3);
}
