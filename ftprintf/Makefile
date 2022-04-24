# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 19:51:26 by tdi-leo           #+#    #+#              #
#    Updated: 2022/02/07 20:31:32 by tdi-leo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c\

OBJS		= ${SRCS:.c=.o}

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

NAME		= libftprintf.a

all:		${NAME}

$(NAME):		${OBJS}
			ar rc ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean ${NAME}
