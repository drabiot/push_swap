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

/*
** Create an array with the given matrix
*/
static char	*create_array(int argc, char **argv)
{
	char	*array;
	int		i;

	array = NULL;
	i = 1;
	if (argc > 2)
	{
		while (i < argc)
		{
			array = ft_strjoin(array, ft_strdup(argv[i]));
			array = ft_strjoin(array, ft_strdup(" "));
			i++;
		}
		return (array);
	}
	return (ft_strdup(argv[1]));
}

/*
** main
*/
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				len_stack_a;
	char			*array;
	char			**matrix;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	array = create_array(argc, argv);
	matrix = ft_split(array, ' ');
	stack_init(&a, matrix, array);
	len_stack_a = size_stack(a);
	if (!is_sorted(a))
	{
		if (len_stack_a >= 4 && len_stack_a <= 5)
			little_sort(&a, &b);
		sort(&a, &b);
	}
	free_stack(&a);
	free(array);
	free_matrix(matrix);
}
