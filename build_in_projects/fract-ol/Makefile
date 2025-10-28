# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: casimarasn <casimarasn@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/02 20:00:58 by msedeno-          #+#    #+#              #
#    Updated: 2025/10/05 14:30:22 by casimarasn       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
INCLUDE = fractol.h
AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft
RM = rm -rf

#librarys
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# MLX42 library
MLX42_DIR = MLX42
MLX42 = $(MLX42_DIR)/build/libmlx42.a
MLX42_FLAGS = -I$(MLX42_DIR)/include
MLX42_LDFLAGS = -ldl -lglfw -pthread -lm

# Update CFLAGS to include MLX42 headers
CFLAGS += $(MLX42_FLAGS)

# object directory
OBJ_DIR = obj

# Using shell command instead of addprefix
SRCS = args_utils.c \
		colors.c \
		errors_free.c \
		fractol.c \
		julia.c \
		mandelbrot.c \
		utils.c \
		
		
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

$(OBJ_DIR)/%.o: %.c $(INCLUDE)
	@mkdir -p $(OBJ_DIR)
	@echo "🛠 Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJS) $(LIBFT) $(MLX42)
	@echo "🔗 Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX42) $(MLX42_LDFLAGS) -o $(NAME)
	@echo "✅ Compilation finished successfully."

#build libft only if libft.a is outdated
$(LIBFT):
	@echo "📦 Building libft..."
	@$(MAKE) -s -C $(LIBFT_DIR)

#build MLX42 only if libmlx42.a is outdated
$(MLX42):
	@echo "📦 Building MLX42..."
	@cmake -S $(MLX42_DIR) -B $(MLX42_DIR)/build >/dev/null 2>&1
	@cmake --build $(MLX42_DIR)/build -j >/dev/null 2>&1

clean:
	@echo "🧹 Cleaning objects..."
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	
fclean: clean
	@echo "🗑 removing executables & libreries..."
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@echo "✅ Cleanup completed successfully."

# Clean MLX42 build directory
mclean:
	@echo "🧹 Cleaning MLX42..."
	@$(RM) $(MLX42_DIR)/build

re: fclean all

.PHONY: all clean fclean re mclean