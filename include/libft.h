/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchartie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:05:39 by tchartie          #+#    #+#             */
/*   Updated: 2023/11/07 00:04:56 by tchartie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

/* ********************************************************** */
/*                                                            */
/*                  Part 1 : Libc functions                   */
/*                                                            */
/* ********************************************************** */

/* ****************************************** */
/*                ft_isalpha.c                */
/*   checks  for  an  alphabetic character    */
/*      which are neither uppercase nor       */
/*                 lowercase                  */
/* ****************************************** */

int		ft_isalpha(int character);

/* ****************************************** */
/*                ft_isdigit.c                */
/*      checks for a digit (0 through 9)      */
/* ****************************************** */

int		ft_isdigit(int character);

/* ****************************************** */
/*                ft_isalnum.c                */
/*    checks for an alphanumeric character    */
/*            It is equivalent to             */
/*         (isalpha(c) || isdigit(c))         */
/* ****************************************** */

int		ft_isalnum(int character);

/* ****************************************** */
/*                ft_isascii.c                */
/*     checks whether c is a 7-bit value      */
/*   that fits into the ASCII character set   */
/* ****************************************** */

int		ft_isascii(int character);

/* ****************************************** */
/*                ft_isprint.c                */
/*    checks for any printable character      */
/*              including space               */
/* ****************************************** */

int		ft_isprint(int character);

/* ****************************************** */
/*                ft_strlen.c                 */
/*    calculates the length of the string     */
/*    excluding the terminating null byte     */
/* ****************************************** */

size_t	ft_strlen(const char *str);

/* ****************************************** */
/*                ft_memset.c                 */
/*   fills the first n bytes of the memory    */
/*       area with the constant byte c        */
/* ****************************************** */

void	*ft_memset(void *s, int c, size_t n);

/* ****************************************** */
/*                 ft_bzero.c                 */
/*  erases  the data in the n bytes of the    */
/*  memory starting at the location pointed   */
/*   to by s, by writing zeros to that area   */
/* ****************************************** */

void	ft_bzero(void *s, size_t n);

/* ****************************************** */
/*                ft_memcpy.c                 */
/*      copies n bytes from memory area       */
/*          src to memory area dest           */
/* ****************************************** */

void	*ft_memcpy(void *dest, const void *src, size_t n);

/* ****************************************** */
/*                ft_memmove.c                */
/*      copies n bytes from memory area       */
/*          src to memory area dest           */
/* ****************************************** */

void	*ft_memmove(void *dest, const void *src, size_t n);

/* ****************************************** */
/*                ft_strlcpy.c                */
/*     copy strings. Take the full size       */
/*      of the buffer and guarantee to        */
/*          NUL-terminate the result          */
/* ****************************************** */

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/* ****************************************** */
/*                ft_strlcat.c                */
/*  concatenate strings. Take the full size   */
/*      of the buffer and guarantee to        */
/*          NUL-terminate the result          */
/* ****************************************** */

size_t	ft_strlcat(char *dst, const char *src, size_t size);

/* ****************************************** */
/*                ft_toupper.c                */
/*    If character is a lowercase letter,     */
/*      returns its uppercase equivalent      */
/* ****************************************** */

int		ft_toupper(int character);

/* ****************************************** */
/*                ft_tolower.c                */
/*    If character is a uppercase letter,     */
/*      returns its lowercase equivalent      */
/* ****************************************** */

int		ft_tolower(int character);

/* ****************************************** */
/*                ft_strchr.c                 */
/*      returns  a  pointer to the first      */
/*       occurrence of the character c        */
/*              in the string s               */
/* ****************************************** */

char	*ft_strchr(const char *s, int c);

/* ****************************************** */
/*                ft_strrchr.c                */
/*      returns  a  pointer to the last       */
/*       occurrence of the character c        */
/*              in the string s               */
/* ****************************************** */

char	*ft_strrchr(const char *s, int c);

/* ****************************************** */
/*                ft_strncmp.c                */
/*          compares the two strings          */
/* returns an integer indicating the result   */
/*             of the comparison:             */
/* •0, if the s1 and s2 are equal             */
/* •a negative value if s1 is less than s2    */
/* •a positive value if s1 is greater than s2 */
/* ****************************************** */

int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* ****************************************** */
/*                ft_memchr.c                 */
/*  scans  the initial n bytes of the memory  */
/*        area pointed to by s for the        */
/*            first instance of c             */
/* ****************************************** */

void	*ft_memchr(const void *s, int c, size_t n);

/* ****************************************** */
/*                ft_memcmp.c                 */
/*  returns an integer less than, equal to,   */
/*      or  greater  than  zero  if  the      */
/*       first  n bytes of s1 is found        */
/* ****************************************** */

int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* ****************************************** */
/*                ft_strnstr.c                */
/*    locates the first occurrence of the     */
/*    null-terminated string little in the    */
/*    string big, where not more than len     */
/*          characters are searched.          */
/* ****************************************** */

char	*ft_strnstr(const char *s1, const char *s2, size_t len);

/* ****************************************** */
/*                 ft_atoi.c                  */
/*    converts the initial portion of the     */
/*            string to an integer            */
/* ****************************************** */

int		ft_atoi(const char *str);

/* ****************************************** */
/*                ft_calloc.c                 */
/* allocates size bytes and returns a pointer */
/*          to the allocated memory           */
/* ****************************************** */

void	*ft_calloc(size_t nmemb, size_t size);

/* ****************************************** */
/*                ft_strdup.c                 */
/*  returns a pointer to a new string which   */
/*       is a duplicate of the string s       */
/* ****************************************** */

char	*ft_strdup(const char *src);

/* ********************************************************** */
/*                                                            */
/*                Part 2 : Additional functions               */
/*                                                            */
/* ********************************************************** */

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* ********************************************************** */
/*                                                            */
/*                         Bonus part                         */
/*                                                            */
/* ********************************************************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif //LIBFT_H
