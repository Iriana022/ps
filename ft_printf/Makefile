#ARGS
NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_utils.c
OBJS = ft_printf.o ft_printf_utils.o
CC = cc
CFLAGS= -Wall -Wextra -Werror
AR = ar rcs
#RULES

all: $(NAME)

$(NAME): libft $(OBJS)
	mv libft.a $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	make -C ./libft
	cp ./libft/libft.a .

clean:
	make -C ./libft clean
	rm -rf *.o

fclean: clean
	make -C ./libft fclean
	rm -rf *.a

re: fclean all

.PHONY: clean fclean re all libft
