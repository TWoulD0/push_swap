NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = operations/push.c operations/rev_rotate.c operations/rotate.c operations/swap.c \
		parsing/parsing_helper.c parsing/parsing.c sorting/chunk_helper.c \
		sorting/cost_helper.c sorting/cost.c sorting/move_to_stack_a.c \
		sorting/push_by_chunks.c sorting/sort_helper.c sorting/sorting.c \
		split/ft_split.c split/ft_split_helper.c helper.c push_swap.c

SRC_BONUS = operations/push.c operations/rev_rotate.c operations/rotate.c operations/swap.c \
		parsing/parsing_helper.c parsing/parsing.c sorting/chunk_helper.c \
		sorting/cost_helper.c sorting/cost.c sorting/move_to_stack_a.c \
		sorting/push_by_chunks.c sorting/sort_helper.c sorting/sorting.c \
		split/ft_split.c split/ft_split_helper.c helper.c checker.c checker_helper.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS)  -o checker

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) checker

re: fclean all

.PHONY: all bonus clean fclean re
.SECONDARY: $(OBJ) $(OBJ_BONUS)