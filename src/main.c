/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:12:44 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/07 19:59:37 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/src/libft.h"

#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
    else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else if (argc > 2)
		argv = &argv[1];
	init_stack(argv);
}
