# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okotsuwa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 07:54:56 by okotsuwa          #+#    #+#              #
#    Updated: 2022/10/31 10:30:21 by okotsuwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c\
			  ft_substr.c ft_strjoin.c ft_itoa.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c\
			  
BONUS		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS		= ${SRCS:.c=.o}

BONUS_OBJ	= ${BONUS:.c=.o}

HEAD		= .

NAME		= libft.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

%o:	%c
	${CC} ${CFLAGS} -c -I ${HEAD} $< -o $@

${NAME}:	${OBJS}
			ar -rcs ${NAME} ${OBJS}

bonus:		${OBJS} ${BONUS_OBJ}
			ar -rcs ${NAME} ${OBJS} ${BONUS_OBJ}
clean:
			${RM} ${OBJS} ${BONUS_OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
