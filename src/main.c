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

int main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*array;
	int				i;

	a = NULL;
	b = NULL;
	array = NULL;
	i = 1;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
	else if (argc > 2)
	{
		while (i < argc)
		{
			array = ft_strjoin(array, argv[i]);
			array = ft_strjoin(array, " ");
			i++;
		}
		argv[1] = array;
		argc = 2;
	}
    if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv);
	display_stack(a);
}
