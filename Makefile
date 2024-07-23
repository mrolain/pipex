# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrolain <mrolain@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 12:36:50 by mrolain           #+#    #+#              #
#    Updated: 2024/07/19 06:46:26 by mrolain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	./src/pipex.c \
		./includes/libft/ft_strlen.c \
		./includes/libft/ft_strjoin.c \
		./includes/libft/ft_split.c \
		./includes/libft/ft_strchr.c \
		./includes/libft/ft_memcpy.c \
		
OBJS = ${SRCS:.c=.o}


CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -f

all:		${NAME}

		
${NAME}:	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}
			
clean:
		@${RM} ${OBJS} infile outfile
		
fclean:	clean
		@${RM} ${NAME}

re:		fclean all