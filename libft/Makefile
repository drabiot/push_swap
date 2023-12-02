# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchartie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 18:05:50 by tchartie          #+#    #+#              #
#    Updated: 2023/11/08 16:06:25 by tchartie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#============ NAME ============#

NAME			=	libft.a

#========= COMPILATOR =========#

CC				=	clang

#=========== FLAGS ============#

CFLAGS			=	-Wall -Wextra -Werror	#Usual flags
GFLAGS			=	$(CFLAGS) -g			#Flag for gdb or valgrind

#========== SOURCES ===========#

SRCS_DIR		=	src/					#Directory of srcs
INCLUDE			=	../include/libft.h		#Directory of header

FT_CTYPE_DIR 	= 	ft_ctype/
FT_CTYPE 		= 	ft_isalpha.c \
					ft_isdigit.c \
					ft_isalnum.c \
					ft_isascii.c \
					ft_isprint.c \
					ft_toupper.c \
					ft_tolower.c \
					ft_atoi.c \
					ft_itoa.c

FT_FDTYPE_DIR	=	ft_fdtype/
FT_FDTYPE		=	ft_putchar_fd.c \
					ft_putstr_fd.c \
					ft_putendl_fd.c \
					ft_putnbr_fd.c

FT_LSTTYPE_DIR	=	ft_lsttype/
FT_LSTTYPE		=	ft_lstnew.c \
					ft_lstadd_front.c \
					ft_lstadd_back.c \
					ft_lstsize.c \
					ft_lstlast.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c

FT_MEMTYPE_DIR	=	ft_memtype/
FT_MEMTYPE		=	ft_memset.c \
					ft_bzero.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_calloc.c

FT_STRTYPE_DIR	=	ft_strtype/
FT_STRTYPE		=	ft_strlen.c \
					ft_strlcpy.c \
					ft_strlcat.c \
					ft_strchr.c \
					ft_strrchr.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strdup.c \
					ft_substr.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_split.c \
					ft_strmapi.c \
					ft_striteri.c

SRC_FILES		+=	$(addprefix $(FT_CTYPE_DIR),$(FT_CTYPE))
SRC_FILES		+=	$(addprefix $(FT_FDTYPE_DIR),$(FT_FDTYPE))
SRC_FILES		+=	$(addprefix $(FT_LSTTYPE_DIR),$(FT_LSTTYPE))
SRC_FILES		+=	$(addprefix $(FT_MEMTYPE_DIR),$(FT_MEMTYPE))
SRC_FILES		+=	$(addprefix $(FT_STRTYPE_DIR),$(FT_STRTYPE))

SRCS			=	$(addprefix $(SRCS_DIR),$(SRC_FILES))

OBJS = $(SRCS:.c=.o)						#Change madatory .c to .o

#========= EXECUTABLE =========#

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c INCLUDE
	$(CC) $(CFLAGS) -c $< -o $@

clean :										#Rule clean (Delete all .o)
	rm -rf $(OBJS)

fclean : clean								#Rule fclean (clean all)
	rm -rf $(NAME)

re : fclean all								#Rule re
	
.PHONY : all clean fclean re
