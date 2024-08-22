### ARGUMENTS
NAME = push_swap
SRC = main.c errors.c ft_atol.c init.c utils.c swap_push.c rotate.c little_sort.c sort.c errors_utils.c sort_utils.c sort_utils2.c sort_utils3.c
SRC_FILES = $(addprefix src/, $(SRC))
CC = cc
CFLAGS = -Wall -Wextra ##-Werror
RM = rm -rf

### RULES

all: $(NAME)

$(NAME): $(SRC_FILES)
	make -C ./ft_printf
	$(CC) $(CFLAGS) -g -I./include $(SRC_FILES) -o $(NAME) -Lft_printf -lftprintf

gen:
	$(CC) ./number_generator/gen.c -o gen

clean:
	make -C ./ft_printf
	$(RM) *.o

fclean: clean
	make -C ./ft_printf fclean
	$(RM) $(NAME) gen

re: fclean all

.PHONY: all clean fclean re
