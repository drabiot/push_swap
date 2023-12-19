/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:57:32 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/19 17:57:33 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "../src/push_swap.h"
#include "../libft/src/libft.h"

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
	char			*array;
	char			**matrix;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	array = create_array(argc, argv);
	matrix = ft_split(array, ' ');
	free_stack(&a);
	free(array);
	free_matrix(matrix);
	return (0);
}
