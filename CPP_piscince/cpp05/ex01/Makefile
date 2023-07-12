# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdi-leo <tdi-leo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 12:43:46 by tdi-leo           #+#    #+#              #
#    Updated: 2023/03/15 15:12:16 by tdi-leo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat

FILES = main.cpp Bureaucrat.cpp Form.cpp

HEADERS = Bureaucrat.hpp

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