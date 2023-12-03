
#============ NAME ============#

NAME		=	push_swap
ARCHIVE		=	push_swap.a

#========= COMPILATOR =========#

CC			=	clang

#=========== FLAGS ============#

CFLAGS		=	-Wall -Wextra -Werror		#Usual flags
GFLAGS		=	$(CFLAGS) -g				#Flag for gdb or valgrind

#========== SOURCES ===========#

SRCS_DIR	=	src/
SRCS_FILES 	=	mainc.c \
				swap_commands.c \
				push_commands.c \
				rotate_commands.c \
				reverse_commands.c

SRCS		=	$(addprefix $(SRCS_DIR),$(SRC_FILES))

INCLUDE		=	./include/push_swap.h		#directory of headers
LIBFT_DIR	=	./libft/					#Path to Libft
LIBFT_NAME	=	libft.a						#Name of Libft
	
OBJS		=	$(SRCS:.c=.o)				#Change mandatory .c to .o

#========= EXECUTABLE =========#

all : $(NAME)

makelibft:									#Make Libft
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT_NAME) .
	mv $(LIBFT_NAME) $(NAME)

$(ARCHIVE) : $(OBJS)
	ar -rcs $(ARCHIVE) $^

$(NAME) : makelibft $(ARCHIVE)
	$(CC) $< -o $@

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean :										#Rule clean (Delete all .o)
	rm -rf $(OBJS)

fclean : clean								#Rule fclean (Clean all)
	rm -rf $(NAME)

re : fclean all								#Rule re

.PHONY : all makelibft clean fclean re