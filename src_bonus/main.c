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

#include "../include/checker.h"
#include "../include/push_swap.h"
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

static void	instructions(t_stack_node **a, t_stack_node **b, char *instruction)
{
	if (!ft_strcmp(instruction, "pa\n"))
		push_a(a, b);
	if (!ft_strcmp(instruction, "pb\n"))
		push_b(b, a);
	if (!ft_strcmp(instruction, "sa\n"))
		swap_a(a);
	if (!ft_strcmp(instruction, "sb\n"))
		swap_b(b);
	if (!ft_strcmp(instruction, "ss\n"))
		swap_all(a, b);
	if (!ft_strcmp(instruction, "ra\n"))
		rotate_a(a);
	if (!ft_strcmp(instruction, "rb\n"))
		rotate_b(b);
	if (!ft_strcmp(instruction, "rr\n"))
		rotate_all(a, b);
	if (!ft_strcmp(instruction, "rra\n"))
		reverse_rotate_a(a);
	if (!ft_strcmp(instruction, "rrb\n"))
		reverse_rotate_b(b);
	if (!ft_strcmp(instruction, "rrr\n"))
		reverse_rotate_all(a, b);
}

static void	return_validation(t_stack_node **a, t_stack_node **b)
{
	if (is_sorted(*a) && size_stack(*b) == 0)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

static void	free_main(t_stack_node **a, char **matrix, char *array)
{
	free_stack(a);
	free(array);
	free_matrix(matrix);
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
	char			*line;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	array = create_array(argc, argv);
	matrix = ft_split(array, ' ');
	stack_init(&a, matrix, array);
	line = get_next_line(0);
	while (line)
	{
		instructions(&a, &b, line);
		if (line)
			free(line);
		line = get_next_line(0);
	}
	return_validation(&a, &b);
	free_main(&a, matrix, array);
	return (0);
}
