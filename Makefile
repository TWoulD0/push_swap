NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRC = helper.c operations.c parsing.c push_swap.c sorting.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SRC_BONUS = checker.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJ) $(OBJ_BONUS)
	$(AR) $(NAME) $(OBJ)  $(OBJ_BONUS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME)
	cc push_swap.c push_swap.a -o push_swap

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus test clean fclean re
.SECONDARY: $(OBJ) $(OBJ_BONUS)