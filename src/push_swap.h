/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:52:16 by tchartie          #+#    #+#             */
/*   Updated: 2023/12/07 15:54:50 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
}						t_stack_node;

/* ********************************************************** */
/*                                                            */
/*                       Append_stack.c                       */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*                stack_init()                */
/*    Initialize the given stack with the     */
/*              given arguments               */
/* ****************************************** */

void					stack_init(t_stack_node **a, char **argv);

/* ********************************************************** */
/*                                                            */
/*                       Error_Check.c                        */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*               error_syntax()               */
/*     Check if given arguments are good      */
/* ****************************************** */

int						error_syntax(char *arg);

/* ****************************************** */
/*             error_repetition()             */
/*      Check if there are not two times      */
/*              the same number               */
/* ****************************************** */

int						error_repetition(t_stack_node *a, int nb);

void					error(t_stack_node **stack, char **argv);

void	display_stack(t_stack_node *stack);
/* ********************************************************** */
/*                                                            */
/*                     Push_Swap Commands                     */
/*                                                            */
/* ********************************************************** */
#endif //PUSH_SWAP_H
