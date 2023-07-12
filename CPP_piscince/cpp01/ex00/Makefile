# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 12:43:46 by tdi-leo           #+#    #+#              #
#    Updated: 2023/02/08 15:38:57 by tdi-leo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

FILES = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

all: $(NAME)

$(NAME) : ${OBJS}
	clang++ -Wall -Wextra -Werror -std=c++98 $(FILES) -o $(NAME)

re: fclean $(NAME)

clean:
	rm -f ${NAME}

fclean: clean

sanitize: 
	clang++ -fsanitize=address -Wall -Wextra -Werror -std=c++98 ${OBJS} -o $(NAME)
.PHONY: all re clean fclean