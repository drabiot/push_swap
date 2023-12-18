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
	int					cheapest;
	int					push_price;
	int					current_pos;
	int					above_median;
	struct s_stack_node	*next;
	struct s_stack_node	*target;
}						t_stack_node;

/* ********************************************************** */
/*                                                            */
/*                        Append_stack                        */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*                stack_init()                */
/*    Initialize the given stack with the     */
/*              given arguments               */
/* ****************************************** */
void			stack_init(t_stack_node **a, char **matrix, char *array);

/* ****************************************** */
/*             Init_stack_utils()             */
/*      Initialize all the nodes in the       */
/*                given stack                 */
/* ****************************************** */
void			init_stack_utils(t_stack_node **a, t_stack_node **b);

/* ****************************************** */
/*            set_position_node()             */
/*     Take a stack and assign each node      */
/*                its position                */
/* ****************************************** */
void			set_position_node(t_stack_node **stack);

/* ****************************************** */
/*            set_position_node()             */
/*     Take a stack and assign each node      */
/*              its target node.              */
/*    The nodes in the stack should point     */
/*       to the smallest number greater       */
/*        than themselves in stack b.         */
/*       If there is no greater number,       */
/*         point to the smallest one          */
/* ****************************************** */
void			set_target_node(t_stack_node **a, t_stack_node *b);

/* ****************************************** */
/*              set_price_node()              */
/*        Take a stack and assign each        */
/*    node its push cost (in instructions)    */
/* ****************************************** */
void			set_price_node(t_stack_node **a, t_stack_node *b);

/* ****************************************** */
/*            set_cheapest_node()             */
/*      Take a stack and check if it is       */
/*        the most economical to push         */
/*           by examining its cost            */
/* ****************************************** */
void			set_cheapest_node(t_stack_node **stack);

/* ********************************************************** */
/*                                                            */
/*                        Error_Check                         */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*               error_syntax()               */
/* Check if given arguments are well-written  */
/* ****************************************** */
int				error_syntax(char *arg);

/* ****************************************** */
/*             error_repetition()             */
/*      Check if there are not two times      */
/*              the same number               */
/* ****************************************** */
int				error_repetition(t_stack_node *a, int nb);

/* ****************************************** */
/*                  error()                   */
/*         Return errors and free the         */
/*     memory of the stack and the matrix     */
/* ****************************************** */
void			error(t_stack_node **stack, char **matrix, char *array);

/* ****************************************** */
/*               free_matrix()                */
/*           Free the given matrix            */
/* ****************************************** */
void			free_matrix(char **matrix);

/* ****************************************** */
/*                free_stack()                */
/*            Free the given stack            */
/* ****************************************** */
void			free_stack(t_stack_node **stack);

/* ********************************************************** */
/*                                                            */
/*                     Push_Swap Commands                     */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*            find_small/biggest()            */
/*      Take a stack and return the node      */
/*      with the smallest/largest value       */
/* ****************************************** */
t_stack_node	*find_biggest(t_stack_node **stack);
t_stack_node	*find_smallest(t_stack_node **stack);

/* ****************************************** */
/*                size_stack()                */
/*           Count the total number           */
/*            of nodes in a stack             */
/* ****************************************** */
int				size_stack(t_stack_node *stack);

/* ****************************************** */
/*                last_node()                 */
/*          Return the last node of           */
/*              the given stack               */
/* ****************************************** */
t_stack_node	*last_node(t_stack_node *stack);

/* ****************************************** */
/*             return_cheapest()              */
/*        Return the cheapest node in         */
/*              the given stack               */
/* ****************************************** */
t_stack_node	*return_cheapest(t_stack_node **stack);

/* ****************************************** */
/*                add_front()                 */
/*     Add a new node in the front (tail)     */
/*              of a given stack              */
/* ****************************************** */
void			add_front(t_stack_node **stack, t_stack_node *new);

/* ****************************************** */
/*                add_fback()                 */
/*     Add a new node in the back (head)      */
/*              of a given stack              */
/* ****************************************** */
void			add_back(t_stack_node **stack, t_stack_node *new);

/* ****************************************** */
/*                   swap()                   */
/*        Swap the first two elements         */
/*                of the stack                */
/* ****************************************** */
void			swap_a(t_stack_node **a);
void			swap_b(t_stack_node **b);
void			swap_all(t_stack_node **a, t_stack_node **b);

/* ****************************************** */
/*                   push()                   */
/*     Take the first element at the top      */
/*       of a stack & put it at the top       */
/*             of an other stack              */
/* ****************************************** */
void			push_a(t_stack_node **a, t_stack_node **b);
void			push_b(t_stack_node **b, t_stack_node **a);

/* ****************************************** */
/*                  rotate()                  */
/*          Shift up all elements of          */
/*               the stack by 1               */
/* ****************************************** */
void			rotate_a(t_stack_node **a);
void			rotate_b(t_stack_node **b);
void			rotate_all(t_stack_node **a, t_stack_node **b);

/* ****************************************** */
/*              reverse_rotate()              */
/*         Shift down all elements of         */
/*              the stack by 1.               */
/* ****************************************** */
void			reverse_rotate_a(t_stack_node **a);
void			reverse_rotate_b(t_stack_node **b);
void			reverse_rotate_all(t_stack_node **a, t_stack_node **b);

/* ********************************************************** */
/*                                                            */
/*                     Sorting Algorithm                      */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*                is_sorted()                 */
/*   Take a stack and check if it is sorted   */
/* ****************************************** */
int				is_sorted(t_stack_node *stack);

/* ****************************************** */
/*                tiny_sort()                 */
/*     Take a stack of 3 elements at most     */
/*            & sort it optimally             */
/* ****************************************** */
void			tiny_sort(t_stack_node **stack);

/* ****************************************** */
/*               little_sort()                */
/*     Take a stack of 5 elements & sort      */
/*       it optimally with tiny_sort()        */
/* ****************************************** */
void			little_sort(t_stack_node **a, t_stack_node **b);

/* ****************************************** */
/*                   sort()                   */
/*      Take a stack & sort it optimally      */
/* ****************************************** */
void			sort(t_stack_node **a, t_stack_node **b);

/* ****************************************** */
/*             finish_rotation()              */
/*   Take a stack and set the cheapest node   */
/*          on the top of the stack           */
/* ****************************************** */
void			finish_rotation(t_stack_node **stack,
					t_stack_node *cheapest,
					char stack_name);

/* ****************************************** */
/*               rotate_both()                */
/*         Rotate the two given stack         */
/* ****************************************** */
void			rotate_both(t_stack_node **a,
					t_stack_node **b,
					t_stack_node *cheapest);

/* ****************************************** */
/*           reverse_rotate_both()            */
/*     Reverse rotate the two given stack     */
/* ****************************************** */
void			reverse_rotate_both(t_stack_node **a,
					t_stack_node **b,
					t_stack_node *cheapest);

/* ****************************************** */
/*             set_rotate_node()              */
/*        Rotate or reverse rotate the        */
/*           two given stacks with            */
/*    rotate_both(), reverse_rotate_both()    */
/*            & finish_rotation()             */
/* ****************************************** */
void			set_rotate_node(t_stack_node **a, t_stack_node **b);

#endif //PUSH_SWAP_H
