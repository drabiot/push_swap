/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:32:47 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/11 20:37:21 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	display_stack(t_stack_node *stack)
{
	t_stack_node	*current_node;

	current_node = stack;
	while (current_node)
	{
		printf("%d->", current_node->value);
		current_node = current_node->next;
	}
}
