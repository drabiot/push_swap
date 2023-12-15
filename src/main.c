/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:58:00 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/11 21:02:49 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/src/libft.h"

#include <stdio.h>

static char *create_array(int argc, char **argv)
{
	char	*array;
	int		i;
	
	array = NULL;
	i = 1;
	if (argc > 2)
	{
		while (i < argc)
		{
			array = ft_strjoin(array, argv[i]);
			array = ft_strjoin(array, " ");
			i++;
		}
		return (array);	
	}
	return(argv[1]);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*array;

	a = NULL;
	b = NULL;
	array = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	argv[1] = create_array(argc, argv);
	argv = ft_split(argv[1], ' ');	
	stack_init(&a, argv);
	if (!is_sorted(a))
	{
		if (size_stack(a) == 2)
			swap_a(&a);
		else if (size_stack(a) == 3)
			tiny_sort(&a);
		else
			sort(&a, &b);
	}
}
