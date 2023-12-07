/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:20:51 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/07 19:53:43 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/src/libft.h"

#include <stdio.h>

void	init_stack(char **argv)
{
	long	nb;
	int		i;
	int		*stack;

	i = 0;
	while (argv[i])
		i++;
	stack = (int *)malloc(sizeof(int) * (i + 1));
	if (!stack)
		return ;
	stack[i] = '\0';
	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
		{
			printf("Syntax Error\n");
			return ;
		}
		nb = ft_atol(argv[i]);
		if (nb > 2147483647 || nb < -2147483648)
		{
			printf("Int overflow Error\n");
			return ;
		}
		if (error_repetition(stack, nb))
		{
			printf("Repetition Error\n");
			return ;
		}
		stack[i] = nb;
		i++;
	}
	printf("%d", i);
}
