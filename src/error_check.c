/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:09:59 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/07 18:15:18 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

static void	free_matrix(char **argv)
{
	int	i;

	i = 0;
	if (!argv || !*argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	error(t_stack_node **stack, char **argv)
{
	free_stack(stack);
	free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}

int	error_syntax(char *arg)
{
	int	i;

	i = 0;
	if (!(arg[i] == '+' || arg[i] == '-' || (arg[i] >= '0' && arg[i] <= '9')))
		return (1);
	if ((arg[i] == '+' || arg[i] == '-')
		&& !(arg[i + 1] >= '0' && arg[i + 1] <= '9'))
		return (1);
	i++;
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	error_repetition(t_stack_node *a, int nb)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == nb)
			return (1);
		a = a->next;
	}
	return (0);
}
