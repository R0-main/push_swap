EXEC=push_swap
CC=cc
CFLAGS=-Wall -Werror -Wextra -I./includes/

SRCS=./src/push_swap.c

OBJS=${SRCS:.c=.o}

all: ${EXEC}

${EXEC} : ${OBJS}
	${CC} ${CFLAGS} -o ${EXEC} ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OBJS}

fclean:	clean
	rm -rf ${EXEC}

re: fclean all

.PHONY: all clean fclean re bonus
