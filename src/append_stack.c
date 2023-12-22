/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:04:04 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/17 22:45:37 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/src/libft.h"

/*
** Create a node & add it on top of the stack
*/
static void	append_node(t_stack_node **stack, int nb)
{
	t_stack_node	*current;
	t_stack_node	*last;

	if (!stack)
		return ;
	current = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!current)
		return ;
	current->next = NULL;
	current->target = NULL;
	current->value = nb;
	current->cheapest = 0;
	current->push_price = 0;
	current->current_pos = 0;
	current->above_median = 0;
	if (!*stack)
		*stack = current;
	else
	{
		last = last_node(*stack);
		last->next = current;
	}
}

/*
** Check the given arguments & Initialize the 
** given stack with the given arguments
*/
void	stack_init(t_stack_node **a, char **matrix, char *array)
{
	long	nbr;
	int		i;

	nbr = 0;
	i = 0;
	if (!matrix || !*matrix)
		error(a, matrix, array);
	while (matrix[i])
	{
		if (!matrix[i])
			error(a, matrix, array);
		if (error_syntax(matrix[i]))
			error(a, matrix, array);
		nbr = ft_atol(matrix[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			error(a, matrix, array);
		if (error_repetition(*a, (int)nbr))
			error(a, matrix, array);
		append_node(a, (int)nbr);
		i++;
	}
}

/*
** Return the cheapest node of the given stack
*/
t_stack_node	*return_cheapest(t_stack_node **stack)
{
	t_stack_node	*head;

	if (!stack || !*stack)
		return (NULL);
	head = *stack;
	while (head)
	{
		if (head->cheapest)
			return (head);
		head = head->next;
	}
	return (NULL);
}
