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

/* ****************************************** */
/*                  error()                   */
/*         Return errors and free the         */
/*     memory of the stack and the matrix     */
/* ****************************************** */

void					error(t_stack_node **stack, char **argv);

/* ********************************************************** */
/*                                                            */
/*                     Push_Swap Commands                     */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*                size_stack()                */
/*           Count the total number           */
/*            of nodes in a stack             */
/* ****************************************** */

int						size_stack(t_stack_node *stack);

/* ****************************************** */
/*                   swap()                   */
/*        Swap the first two elements         */
/*                of the stack                */
/* ****************************************** */

void					swap_a(t_stack_node **a);
void					swap_b(t_stack_node **b);
void					swap_all(t_stack_node **a, t_stack_node **b);

/* ****************************************** */
/*                   push()                   */
/*     Take the first element at the top      */
/*       of a stack & put it at the top       */
/*             of an other stack              */
/* ****************************************** */


/* ****************************************** */
/*                  rotate()                  */
/*          Shift up all elements of          */
/*               the stack by 1               */
/* ****************************************** */

void					rotate_a(t_stack_node **a);
void					rotate_b(t_stack_node **b);
void					rotate_all(t_stack_node **a, t_stack_node **b);

/* ****************************************** */
/*              reverse_rotate()              */
/*         Shift down all elements of         */
/*              the stack by 1.               */
/* ****************************************** */



void	display_stack(t_stack_node *stack);

#endif //PUSH_SWAP_H
