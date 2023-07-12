# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 12:43:46 by tdi-leo           #+#    #+#              #
#    Updated: 2023/02/11 11:37:31 by tdi-leo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRCS = megaphone.cpp

OBJS		:= ${SRCS:.c=.o}
all: $(NAME)

$(NAME) : ${OBJS}
	clang++ -Wall -Wextra -Werror -std=c++98 ${OBJS} -o $(NAME)

re: fclean $(NAME)

clean:
	rm -f megaphone

fclean: clean

.PHONY: all re clean fclean