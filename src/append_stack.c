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

#include "push_swap.h"
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
void	stack_init(t_stack_node **a, char **argv)
{
	long	nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error(a, argv);
		nbr = ft_atol(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			error(a, argv);
		if (error_repetition(*a, (int)nbr))
			error(a, argv);
		append_node(a, (int)nbr);
		i++;
	}
}
