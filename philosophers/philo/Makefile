SRC		=	actions.c atoi.c creation.c main.c monitor.c printer.c timing.c thread.c

SRCS	=	$(addprefix src/, $(SRC))

OBJS		:= ${SRCS:.c=.o}

CC			= @gcc

RM			= @rm -f *.a && rm -f *.o

FLAGS		= -g -Wall -Wextra -Werror

NAME		= philo

DEBUG 		= ${CC} -g -fsanitize=address ${OBJS} -o ${NAME}

RACE		= ${CC} -g -fsanitize=thread ${OBJS} -o ${NAME}

${NAME}:	${OBJS}
			@${CC} ${OBJS} -o ${NAME}
			$(info [Making  ..])


all:		${NAME}

bonus:		${NAME}

clean:
			${RM} ${OBJS}
			$(info [cleaning objects ..])

fclean:		clean
			${RM} ${NAME}
			$(info [cleaning all ..])

sanitize:	${OBJS}
			@${DEBUG}
			${info [Making with fsanitize=address ...]}

race:		${OBJS}
			@${RACE}
			${info [Making with fsanitize=thread ...]}

re:			fclean ${NAME}