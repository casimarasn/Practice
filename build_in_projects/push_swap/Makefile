NAME = push_swap
INCLUDE = push_swap.h
AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft -Ift_printf
RM = rm -rf

OBJDIR = obj

#librarys
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

FILES = algorithm_chunk.c \
		algorithm_costs.c \
		arguments.c \
		build_stack.c \
		chunk_moves.c \
		cost_moves.c \
		distance_chunk.c \
		free.c \
		handle_numbers.c \
		is_valid.c \
		main.c \
		multi_moves.c \
		ps_moves.c \
		push_swap.c \
		r_moves.c \
		utils_args.c \
		utils_stacks.c \

OBJS = $(addprefix $(OBJDIR)/, $(FILES:%.c=%.o))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(OBJDIR)/%.o: %.c $(INCLUDE)
	@mkdir -p $(OBJDIR)
	@echo "🛠 Compilando $<..."
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@echo "🔗 Enlazando $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "✅ Compilación finalizada."

#build libft only if libft.a is outdated
$(LIBFT):
	@echo "📦 Construyendo libft..."
	@$(MAKE) -s -C $(LIBFT_DIR)

#build ft_printf only if libftprintf.a is outdated
$(PRINTF):
	@echo "📦 Construyendo printf..."
	@$(MAKE) -s -C $(PRINTF_DIR)

clean:
	@echo "🧹 Limpiando objetos y dependencias..."
	@$(RM) $(OBJDIR) *.d
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(PRINTF_DIR) clean

fclean: clean
	@echo "🗑 Eliminando ejecutables y librerías..."
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(MAKE) -s -C $(PRINTF_DIR) fclean
	@echo "✅ Limpieza completada."
re: fclean all

-include $(DEPS) # Include automatically generated dependencies

.PHONY: all clean fclean re