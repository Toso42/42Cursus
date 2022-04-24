# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:57:24 by tdi-leo           #+#    #+#              #
#    Updated: 2022/04/23 15:58:39 by tdi-leo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= server.c

SRCS2		= client.c

LIBFT		= @cd libft && make

LIBFTA		= libft/libft.a

RMLIB		= @cd libft && make fclean

OBJS		= ${SRCS:.c=.o}

OBJS2		= ${SRCS2:.c=.o}

CC			= @gcc

RM			= @rm -f *.a && rm -f *.o

CFLAGS		= -g -Wall -Wextra -Werror

NAME		= server

CLIENT		= client

DEBUG 		= -g -fsanitize=address

${NAME}:	${OBJS} 
			$(shell make -C libft | 2>/dev/null)
			@${CC} ${CFLAGS} ${OBJS} ${LIBFTA} -o ${NAME}
			$(info [Making server ..])

${CLIENT}:	${OBJS2}
			$(shell make -C libft | 2>/dev/null)
			@${CC} ${CFLAGS} ${OBJS2} ${LIBFTA} -o ${CLIENT}
			$(info [Making client ..])

all:		${NAME} ${CLIENT}

clean:		
			${RM} ${OBJS} ${OBJS2}#clean project only
			$(info [cleaning objects ..])

fclean:		clean	#clean project and library
			${RMLIB}
			${RM} ${NAME} ${CLIENT}
			$(info [cleaning project and library ..])

re:			fclean ${NAME} ${CLIENT}
