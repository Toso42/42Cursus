# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 14:57:24 by tdi-leo           #+#    #+#              #
#    Updated: 2022/04/01 15:59:25 by tdi-leo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= pushswap.c checks.c checks2.c checks3.c library.c\
				library2.c library3.c library4.c lis.c rules.c rules2.c\
				fillra.c fillrra.c fillrbs.c tablecalc.c tablecreator.c\
				initializers.c preps.c preps2.c exec.c\

SRCS2		= checker.c checker2.c checker3.c checker4.c checks.c checks2.c\
				checks3.c library.c library2.c library3.c library4.c\
				rules.c rules2.c fillra.c fillrra.c fillrbs.c tablecalc.c\
				tablecreator.c initializers.c exec.c lis.c\

OBJS		= ${SRCS:.c=.o}

OBJS2		= ${SRCS2:.c=.o}

CC			= gcc

RM			= rm -f

CFLAGS		= -g -Wall -Wextra -Werror

NAME		= push_swap

BONUS		= checker_Mac

DEBUG 		= -g -fsanitize=address

${NAME}:		${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

bonus:		${BONUS}

${BONUS}:		${OBJS2}
			${CC} ${CFLAGS} ${OBJS2} -o ${BONUS}

all:		${NAME} ${BONUS}

clean:
			${RM} ${OBJS} ${OBJS2}

fclean:		clean
			${RM} ${NAME} ${BONUS}

re:			fclean ${NAME} ${BONUS}
