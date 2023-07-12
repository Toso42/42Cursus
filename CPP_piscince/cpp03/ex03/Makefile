# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 12:43:46 by tdi-leo           #+#    #+#              #
#    Updated: 2023/02/13 20:03:52 by tdi-leo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = DiamondTrap

FILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJS=${FILES:.cpp=.o}

$(NAME) : $(OBJS)
	c++ -Wall -Wextra -Werror -std=c++98 -Wshadow $(OBJS) -o $(NAME)

all: $(NAME)

%.o : %.cpp
	c++ -Wall -Wextra -Werror -std=c++98 -c $< -o $@

re: fclean $(NAME)

clean:
	rm -f ${NAME} *.o

fclean: clean

sanitize: 
	c++ -fsanitize=address -Wall -Wextra -Werror -std=c++98 ${OBJS} -o $(NAME)

.PHONY: all re clean fclean