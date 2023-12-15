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

#========= COMPILATOR =========#

CC		=			clang

#=========== FLAGS ============#

GFLAGS		=		-Wall -Wextra -Werror	#Usual flags
CFLAGS		=		$(GFLAGS) -g			#Flag for gdb or valgrind

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

LIBFT_DIR	=		libft
LIBFT_NAME	=		libft.a

SRCS_DIR	=		src/
OBJS_DIR	=		obj/

SRCS		=		main.c \
					append_stack.c \
					error_check.c \
					commands_utils.c \
					swap_commands.c \
					push_commands.c \
					rotate_commands.c \
					reverse_rotate_commands.c \
					sort.c \
					sort_utils.c \
					tiny_sort.c

OBJS		=		$(SRCS:.c=.o)

SRCS_F		=		$(addprefix $(SRCS_DIR),$(SRCS))
OBJS_F		=		$(addprefix $(OBJS_DIR),$(OBJS))


#========= EXECUTABLE =========#

all :				$(NAME)

makelibft :
					@make -C $(LIBFT_DIR) all --no-print-directory

$(NAME) : 			$(OBJS_F) | makelibft
					@$(CC) $(OBJS_F) -o $(NAME) -Llibft -lft
					@echo "$(GREEN)Push_swap successfully compiled! $(BASE_COLOR)"

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.c $(INCLUDE)
					@mkdir -p $(OBJS_DIR)
					@echo "$(YELLOW)Compiling: $< $(BASE_COLOR)"
					@$(CC) $(CFLAGS) -c $< -o $@

clean :
					@rm -rf $(OBJS_DIR)
					@make -C $(LIBFT_DIR) clean --no-print-directory
					@echo "$(BLUE)Push_swap objects files cleanned! $(BASE_COLOR)"

fclean :
					@rm -rf $(OBJS_DIR)
					@echo "$(BLUE)Push_swap objects files cleanned! $(BASE_COLOR)"
					@rm -rf $(NAME)
					@make -C $(LIBFT_DIR) fclean --no-print-directory
					@echo "$(CYAN)Push_swap executable file cleanned! $(BASE_COLOR)"
					

re :				fclean all

.PHONY :			all makelibft clean fclean re
