/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:04:04 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/07 17:48:05 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/src/libft.h"

static void	append_node(t_stack_node **stack, int nb)
{
	t_stack_node	*current_node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	current_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!current_node)
		return ;
	current_node->next = NULL;
	current_node->value = nb;
	if (!*stack)
		*stack = current_node;
	else
	{
		last_node = *stack;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = current_node;
	}
}

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
