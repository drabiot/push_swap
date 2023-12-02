
#============ NAME ============#

NAME = push_swap

#========= COMPILATOR =========#

CC = clang

#=========== FLAGS ============#

CFLAGS = -Wall -Wextra -Werror		#Usual flags
GFLAGS = $(CFLAGS) -g				#Flag for gdb or valgrind

#========== SOURCES ===========#

SRCS = mainc.c \
	swap_commands.c \
	push_commands.c \
	rotate_commands.c \
	reverse_commands.c

INCLUDE = /include					#directory of headers
	
OBJS = $(SRCS:.c=.o)				#Change mandatory .c to .o

#========= EXECUTABLE =========#

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :								#Rule clean (Delete all .o)
	rm -rf $(OBJS)

fclean : clean						#Rule fclean (Delete all .o & libft.a)
	rm -rf $(NAME)

re : fclean all						#Rule re (Delete all .o & libft.a, Create all .o and libft.a)

.PHONY : all clean fclean re