NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
OBJ_DIR = obj/
SRC_DIR = srcs/

SRC_1 = push_swap.c \

SRC_2 =	execute_node.c \
		ft_split.c \
		execute_node_reverse.c \
		operations.c \
		utils.c \
		utils_2.c \
		error_checker.c \
		ft_isdigit.c \
		node_update_reverse.c \
		node_update_utils.c \
		node_update.c \
		operations2.c \
		mem_man.c \

			

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}



.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}

all: ${NAME} ${BONUS}

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME} ${BONUS}

fclean: clean
	${RM} ${NAME}

re: clean all

.PHONY: all clean fclean re bonus