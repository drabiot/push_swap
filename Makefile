# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchartie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 09:42:17 by tchartie          #+#    #+#              #
#    Updated: 2023/12/04 09:42:21 by tchartie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#============ NAME ============#

NAME		=		push_swap
ARCHIVE		=		push_swap.a

#========= COMPILATOR =========#

CC		=			clang

#=========== FLAGS ============#

CFLAGS		=		-Wall -Wextra -Werror	#Usual flags
GFLAGS		=		$(CFLAGS) -g			#Flag for gdb or valgrind

#=========== COLOR ============#

BASE_COLOR 	=		\033[0;39m
GRAY 		=		\033[0;90m
RED 		=		\033[0;91m
GREEN 		=		\033[0;92m
YELLOW 		=		\033[0;93m
BLUE 		=		\033[0;94m
MAGENTA		=		\033[0;95m
CYAN 		=		\033[0;96m
WHITE		=		\033[0;97m

#========== SOURCES ===========#

INCLUDE		=		src/push_swap.h			#Directory of headers

LIBFT_DIR	=		libft/					#Path to Libft
LIBFT_NAME	=		libft.a					#Name of Libft

SRCS_DIR	=		src/
OBJS_DIR	=		obj/

SRCS		=		main.c \
					swap_commands.c \
					push_commands.c \
					rotate_commands.c \
					reverse_commands.c

OBJS		=		$(SRCS:.c=.o)

SRCS_F		=		$(addprefix $(SRCS_DIR),$(SRCS))
OBJS_F		=		$(addprefix $(OBJS_DIR),$(OBJS))


#========= EXECUTABLE =========#

all :				$(NAME)

makelibft:
					make -C $(LIBFT_DIR)
					cp $(LIBFT_DIR)$(LIBFT_NAME) .
					mv $(LIBFT_NAME) $(NAME)

$(NAME) : 			$(OBJS_F) | makelibft
					$(CC)  $(OBJS_F) -o $(NAME) -L$(LIBFT_DIR) -lft $(OBJS_F)

%.o : 				%.c $(INCLUDE)
					$(CC) $(CFLAGS) -c $< -o $@

clean :
					rm -rf $(OBJS)

fclean :			clean
					rm -rf $(NAME)

re :				fclean all

.PHONY :			all makelibft clean fclean re
