NAME = push_swap
CC = cc -g
CFLAGS = -Werror -Wextra -Wall -I$(LIBFT_INC) -Iincl

SRC_DIR = src
SRCS = $(SRC_DIR)/main.c \


OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

UTILS_DIR = utils
UTILS = $(UTILS_DIR)/cleaner.c \
	$(UTILS_DIR)/parsing_utils.c
UTILS_OBJ	= $(addprefix $(OBJ_DIR)/, $(notdir $(UTILS:.c=.o)))


LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = $(LIBFT_DIR)/includes
LIBFT_LIB = -L$(LIBFT_DIR) -lft

#Reglas 👽

all: $(OBJ_DIR) $(NAME)
$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@echo "Directorio objetos creado con exito."

$(NAME) : $(UTILS_OBJ) $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(UTILS_OBJ) $(LIBFT) $(LIBFT_LIB) -o $(NAME)
	@echo "✨ Voilà push_swap está listo."

$(LIBFT):
	@echo "🔨 Construyendo libft..."
	@make -C $(LIBFT_DIR)
	@echo "libft construida con éxito."

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	@echo "!borrando objetos"
	@rm -rf $(OBJ_DIR) $(UTILS_OBJ)
	@rm -rf $(LIBFT_DIR)/objects

fclean: clean
	@echo "borrando ejecutable"
	@rm -rf $(NAME)
	@rm -rf $(LIBFT_DIR)/libft.a

re: fclean all

.PHONY:  all clean fclean re
