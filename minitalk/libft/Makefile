# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdi-leo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 12:49:58 by tdi-leo           #+#    #+#              #
#    Updated: 2022/04/23 16:57:52 by tdi-leo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
  				ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c\
				ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
				ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c\
				ft_split.c ft_strchr.c ft_strrchr.c ft_strdup.c\
  				ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c\
				ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c\
				ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\
				ft_printf.c ft_printf_utils.c ft_printf_utils2.c ft_printbits.c\

OBJS		= ${SRCS:.c=.o}

SRCS2		=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c\
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c\
				ft_lstnew.c ft_lstsize.c ft_lstmap.c\

BONUS_OBJS	= ${SRCS2:.c=.o}

CC			= @gcc

RM			= @rm -f

CFLAGS		= -g -Wall -Wextra -Werror

NAME = libft.a

BONUS = lst.a

${NAME}:	${OBJS}
			@ar rc ${NAME} ${OBJS}

bonus:		${BONUS}

${BONUS}:	${BONUS_OBJS}
			@ar rc ${BONUS} ${BONUS_OBJS}

all:		${NAME} ${BONUS}

clean:
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME} ${BONUS}

re:			fclean ${NAME}
