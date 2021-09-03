NAME = so_long
LIB_DIR = libft
LIBFT = libft.a
MLX_DIR	= minilibx-linux
MLX = libmlx_Linux.a

# Config
# ****************************************************************************

CC = gcc
CFLAGS = $(INCLUDE) #-Wall -Werror -Wextra
INCLUDE = -I includes/ -I $(LIB_DIR)/includes/ -I $(MLX_DIR)/
DEBUG = -g -fsanitize=address
LIBFLAGS = -L $(LIB_DIR) -lft
# Source files
# ****************************************************************************

MAIN_DIR	=	main/
MAIN_FILES	=	main.c \
				#xxxx.c
MAIN_SRCS	 =	$(addprefix $(MAIN_DIR), $(MAIN_FILES))

INPUT_DIR	=	input/
INPUT_FILES	=	map_input.c \
				#xxxx.c
INPUT_SRCS =	$(addprefix $(INPUT_DIR), $(INPUT_FILES))

ERROR_DIR 	=	error/
ERROR_FILES	=	error_print.c \
				free.c \
				#xxxx.c
ERROR_SRCS	=	$(addprefix $(ERROR_DIR), $(ERROR_FILES))

SRC_FILES =			$(MAIN_SRCS) \
					$(INPUT_SRCS) \
					$(ERROR_SRCS) \

# addprefix

SRC_DIR = srcs/

OBJ_DIR = objs/
OBJS = $(SRC_FILES:%.c=$(OBJ_DIR)%.o)
MAIN_OBJS = $(MAIN_FILES:%.c=$(OBJ_DIR)main/%.o)
INPUT_OBJS = $(INPUT_FILES:%.c=$(OBJ_DIR)input/%.o)
ERROR_OBJS = $(ERROR_FILES:%.c=$(OBJ_DIR)error/%.o)

# Recipe
# ****************************************************************************

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)

$(OBJS): $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)$(MAIN_DIR)
	mkdir -p $(OBJ_DIR)$(INPUT_DIR)
	mkdir -p $(OBJ_DIR)$(ERROR_DIR)
	mkdir -p $(OBJ_DIR)$(ECHO_DIR)

debug: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(DEBUG) $(LIBFLAGS) $(OBJS) -o $(NAME)

clean:
	make clean -C $(LIB_DIR)
	rm -rf $(OBJ_DIR)
	rm -fr *.dSYM

fclean:
	make fclean -C $(LIB_DIR)
	rm -rf $(NAME) $(OBJ_DIR)
	rm -fr *.dSYM

re: fclean all
.PHONY: all clean fclean re
