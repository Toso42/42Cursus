# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 12:43:46 by tdi-leo           #+#    #+#              #
#    Updated: 2023/02/22 11:05:32 by tdi-leo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FarmVille

FILES = main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

HEADERS = Animal.hpp Dog.hpp Cat.hpp Brain.hpp

OBJS=${FILES:.cpp=.o}

$(NAME) : $(OBJS) $()
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