
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

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

void	init_stack(char **argv);

/* ********************************************************** */
/*                                                            */
/*                       Error_Check.c                        */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*               error_syntax()               */
/*     Check if given arguments are good      */
/* ****************************************** */

int		error_syntax(char *arg);

/* ****************************************** */
/*             error_repetition()             */
/*      Check if there are not two times      */
/*              the same number               */
/* ****************************************** */

int		error_repetition(int *stack, int nb);

/* ********************************************************** */
/*                                                            */
/*                     Push_Swap Commands                     */
/*                                                            */
/* ********************************************************** */

#endif //PUSH_SWAP_H
