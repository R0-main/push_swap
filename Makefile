EXEC=push_swap
CC=cc
CFLAGS=-Wall -Werror -Wextra -I./includes/

SRCS=./src/push_swap.c\
	./src/lists/utils.c\
	./src/parsing/parsing.c\
	./src/utils/ft_atoi.c\
	./src/utils/ft_strlen.c\
	./src/utils/ft_substr.c\
	./src/utils/is_not_only_digits.c\
	./src/utils/ft_split.c

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
