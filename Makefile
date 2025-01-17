EXEC		=	push_swap
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -I./includes/

COMMON_SRCS	=\
			./src/pushs.c\
			./src/swaps.c\
			./src/rotates.c\
			./src/reverse_rotates.c\
			./src/link_nodes.c\
			./src/getters.c\
			./src/fast-sort/fast-sort.c\
			./src/lists/add.c\
			./src/lists/utils.c\
			./src/lists/is_sorted.c\
			./src/parsing/parsing.c\
			./src/parsing/parser_utils.c\
			./src/lists/values_init.c\
			./src/utils/ft_atoi.c\
			./src/utils/ft_strlen.c\
			./src/utils/ft_substr.c\
			./src/utils/ft_split.c

SRCS		=\
			./src/main.c\
			./src/push_swap.c\
			${COMMON_SRCS}

BONUS_SRCS	=\
			./src/checker/checker.c\
			./src/checker/parsing.c\
			./src/checker/dependencies/gnl/get_next_line.c\
			./src/checker/dependencies/gnl/get_next_line_utils.c\
			${COMMON_SRCS}

OBJS		=	${SRCS:.c=.o}
BONUS_OBJS	=	${BONUS_SRCS:.c=.o}

CHECKER_EXE	=	checker.out

all: ${EXEC}

${EXEC} : ${OBJS}
	${CC} ${CFLAGS} -o ${EXEC} ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OBJS}
	rm -rf ${BONUS_OBJS}

fclean:	clean
	rm -rf ${EXEC}
	rm -rf ${CHECKER_EXE}

bonus: ${BONUS_OBJS}
	${CC} ${CFLAGS} -o ${CHECKER_EXE} ${BONUS_OBJS}

re: fclean all

.PHONY: all clean fclean re bonus
