/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:08:37 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/20 16:24:16 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

/* ********************************************************** */
/*                                                            */
/*                       get_next_line                        */
/*                                                            */
/* ********************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif //BUFER_SIZE

/* ****************************************** */
/*               get_next_line                */
/*     Take a file descriptor and return      */
/*                   a line                   */
/* ****************************************** */
char	*get_next_line(int fd);

/* ****************************************** */
/*                 read_buff                  */
/*     Take a file descriptor and read it     */
/* ****************************************** */
char	*read_buff(int fd, char *stash);

/* ****************************************** */
/*                add_to_line                 */
/*       Take the line finished by a \n       */
/*                & return it                 */
/* ****************************************** */
char	*add_to_line(char *stash);

/* ****************************************** */
/*                clean_stash                 */
/*     Remove the line add into the stash     */
/* ****************************************** */
char	*clean_stash(char *stash);

/* ********************************************************** */
/*                                                            */
/*                    get_next_line_utils                     */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*                  new_line                  */
/*   See if there a newline into the stash    */
/* ****************************************** */
int		new_line(char *str);

/* ****************************************** */
/*               ft_strjoin_gnl               */
/*    Take two string and concatenate them    */
/* ****************************************** */
char	*ft_strjoin_gnl(char *s1, char *s2);


/* ****************************************** */
/*                 ft_strccpy                 */
/*         Take a string and copy it          */
/* ****************************************** */
char	*ft_strccpy(char *dst, const char *src, int check_nl);

#endif //GET_NEXT_LINE_H
