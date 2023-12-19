# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchartie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 09:42:17 by tchartie          #+#    #+#              #
#    Updated: 2023/12/19 17:36:24 by tchartie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#============ NAME ============#

NAME		=		push_swap
ARCHIVE		=		push_swap.a
NAME_BONUS	=		checker

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

INCLUDE_DIR	=		include
INCLUDE		=		$(INCLUDE_DIR)/push_swap.h
INCLUDE_B	=		$(INCLUDE_DIR)/checker.h

LIBFT_DIR	=		libft
LIBFT_NAME	=		libft.a

SRCS_DIR	=		src/
SRCS_B_DIR	=		src_bonus/
OBJS_DIR	=		obj/
OBJS_A_DIR	=		obj_archive/
OBJS_B_DIR	=		obj_bonus/

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
					
SRCS_ARCH	=		append_stack.c \
					error_check.c \
					commands_utils.c \
					swap_commands.c \
					push_commands.c \
					rotate_commands.c \
					reverse_rotate_commands.c \
					sort.c \
					sort_utils.c \
					tiny_sort.c

SRCS_BONUS	=		main.c \
					get_next_line.c \
					get_next_line_utils.c

OBJS		=		$(SRCS:.c=.o)
OBJS_ARCH	=		$(SRCS_ARCH:.c=.o)
OBJS_BONUS	=		$(SRCS_BONUS:.c=.o)

SRCS_F		=		$(addprefix $(SRCS_DIR),$(SRCS))
SRCS_ARCH_F	=		$(addprefix $(SRCS_DIR),$(SRCS_ARCH))
SRCS_B_F	=		$(addprefix $(SRCS_B_DIR),$(SRCS_BONUS))

OBJS_F		=		$(addprefix $(OBJS_DIR),$(OBJS))
OBJS_ARCH_F	=		$(addprefix $(OBJS_A_DIR),$(OBJS_ARCH))
OBJS_B_F	=		$(addprefix $(OBJS_B_DIR),$(OBJS_BONUS))


#========= EXECUTABLE =========#

all :				$(NAME)

bonus :				$(NAME_BONUS)

makelibft :
					@make -C $(LIBFT_DIR) all --no-print-directory

$(NAME) : 			$(OBJS_F) | makelibft
					@$(CC) $(OBJS_F) -o $(NAME) -Llibft -lft -I$(INCLUDE_DIR)
					@echo "$(GREEN)Push_swap successfully compiled! $(BASE_COLOR)"

$(OBJS_DIR)%.o :	$(SRCS_DIR)%.c $(INCLUDE)
					@mkdir -p $(OBJS_DIR)
					@echo "$(YELLOW)Compiling: $< $(BASE_COLOR)"
					@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(ARCHIVE) :		$(OBJS_ARCH_F) | makelibft
					@ar -rcs $(ARCHIVE) $(OBJS_ARCH_F)
					@echo "$(GREEN)Push_swap.a successfully compiled! $(BASE_COLOR)"

$(OBJS_A_DIR)%.o :	$(SRCS_DIR)%.c $(INCLUDE)
					@mkdir -p $(OBJS_A_DIR)
					@echo "$(YELLOW)Compiling: $< $(BASE_COLOR)"
					@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(NAME_BONUS) :		$(OBJS_B_F) $(ARCHIVE) | makelibft all
					@$(CC) $(OBJS_B_F) $(ARCHIVE) -o $(NAME_BONUS) -Llibft -lft -I$(INCLUDE_DIR)
					@echo "$(GREEN)Checker successfully compiled! $(BASE_COLOR)"
					@rm -rf $(ARCHIVE)
					@rm -rf $(OBJS_A_DIR)			

$(OBJS_B_DIR)%.o :	$(SRCS_B_DIR)%.c $(INCLUDE) $(INCLUDE_B)
					@mkdir -p $(OBJS_B_DIR)
					@echo "$(YELLOW)Compiling $< $(BASE_COLOR)"
					@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean :
					@rm -rf $(OBJS_DIR)
					@rm -rf $(OBJS_B_DIR)
					@make -C $(LIBFT_DIR) clean --no-print-directory
					@echo "$(BLUE)Push_swap & checker objects files cleanned! $(BASE_COLOR)"

fclean :
					@rm -rf $(OBJS_DIR)
					@rm -rf $(OBJS_B_DIR)
					@echo "$(BLUE)Push_swap & checker objects files cleanned! $(BASE_COLOR)"
					@rm -rf $(NAME)
					@rm -rf $(NAME_BONUS)
					@make -C $(LIBFT_DIR) fclean --no-print-directory
					@echo "$(CYAN)Push_swap & checker executable file cleanned! $(BASE_COLOR)"
					

re :				fclean all

.PHONY :			all makelibft bonus clean fclean re
