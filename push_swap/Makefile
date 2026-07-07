NAME = push_swap
BONUS = checker
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
OBJ_DIR = obj/
BONUS_OBJ_DIR = bonus_obj/
SRC_DIR = srcs/
CHECKER_DIR = checker_srcs/

SRC_1 = push_swap.c execute_node.c ft_split.c execute_node_reverse.c operations.c \
	utils.c utils_2.c error_checker.c ft_isdigit.c node_update_reverse.c \
	node_update_utils.c node_update.c operations2.c mem_man.c

BONUS_SRC = checker.c operations.c operations2.c error_checker.c mem_man.c utils.c utils_2.c ft_isdigit.c get_next_line.c get_next_line_utils.c ft_split.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_1))
BONUS_SRC := $(addprefix $(CHECKER_DIR)/, $(BONUS_SRC))

OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)%.o,$(SRC))
BONUS_OBJ = $(patsubst $(CHECKER_DIR)/%.c,$(BONUS_OBJ_DIR)%.o,$(BONUS_SRC))

$(OBJ_DIR)%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)%.o: $(CHECKER_DIR)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(BONUS): $(BONUS_OBJ)
	$(CC) $(FLAGS) $(BONUS_OBJ) -o $(BONUS)

all: $(NAME) $(BONUS)

clean:
	$(RM) -r $(OBJ_DIR) $(BONUS_OBJ_DIR)
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) -r $(OBJ_DIR) $(BONUS_OBJ_DIR)
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re

