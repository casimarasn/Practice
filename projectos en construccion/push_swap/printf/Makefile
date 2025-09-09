NAME = libftprintf.a
INCLUDE = ft_print.h
AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

FILES = ft_printf.c \
		ft_print_format.c \
		ft_print_char.c \
		ft_print_string.c \
		ft_print_percent.c \
		ft_print_nbr.c \
		ft_print_unsigned.c \
		ft_print_hexdecma.c \
		ft_print_hexdecmi.c \
		ft_print_pointer.c


OBJS = $(FILES:%.c=%.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re