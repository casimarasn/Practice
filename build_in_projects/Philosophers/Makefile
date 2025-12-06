# ========================================================================== #
#                                   COLORS                                   #
# ========================================================================== #

DEF_COLOR	= \033[0;39m
GRAY		= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m

# ========================================================================== #
#                                   PROGRAM                                  #
# ========================================================================== #

NAME		= philo

# ========================================================================== #
#                                   PATHS                                    #
# ========================================================================== #

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= include

# ========================================================================== #
#                                   FILES                                    #
# ========================================================================== #

SRC_FILES	= args_init.c \
			args_utils.c \
			errors_free.c \
			main.c \
			routine.c \
			routine_utils.c \
			table.c \
			big_sister.c \


SRCS		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
HEADER		= $(INC_DIR)/philo.h

# ========================================================================== #
#                                COMPILATION                                 #
# ========================================================================== #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR) #-fsanitize=thread
PTHREAD		= -pthread #-fsanitize=thread
RM			= rm -rf
HELGRIND = valgrind --tool=helgrind --history-level=approx -s
# ========================================================================== #
#                                   RULES                                    #
# ========================================================================== #

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(PTHREAD) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(DEF_COLOR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)Compiling: $(CYAN)$<$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(YELLOW)✓ Object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)✓ Executable removed!$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re