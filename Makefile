# --------------- Makefile ------------ #

NAME			:= fractol

# ----------- Source and object files ------------- #

SRC_DIR			:= src
SRCS			:= main.c display.c initialise.c color.c math.c keyboard.c
SRCS			:= $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR			:= .build
OBJS			:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# --------------- Libraries and header files ------------- #

INC_DIR				:= include

MLX_DIR				:= MLX42
LIBS_TARGET_MLX		:= $(MLX_DIR)/build/libmlx42.a

LIB42_DIR			:= 42_lib
LIB42_TARGET		:= 42_lib/libftprintfgnl.a

LIBS_ALL			:= $(LIBS_TARGET_MLX) $(LIB42_TARGET) -ldl -lglfw -pthread -lm

# --------------- Flags --------------- #

CFLAGS				:= -Wall -Wextra -Werror -g -Ofast -I$(INC_DIR)
ENSURE_BUILD_DIR	:= mkdir -p $(OBJ_DIR)
RM					:= rm -rf

# --------- Compilation/rules --------- #

all: $(NAME)

$(NAME): $(LIBS_TARGET_MLX) $(LIB42_TARGET) $(OBJS)
	cc $(CFLAGS) $(OBJS) $(LIBS_ALL) -o $(NAME)
	@echo $(Blue) fractol was compiled ✅ $(Color_Off)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(ENSURE_BUILD_DIR)
	cc $(CFLAGS) -c $< -o $@

$(LIBS_TARGET_MLX):
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build && cmake --build $(MLX_DIR)/build -j4
	@echo $(Blue) MLX42 Complete ✅ $(Color_Off)

$(LIB42_TARGET):
	@$(MAKE) -C	$(LIB42_DIR)
	@echo $(Blue) 42_Lib Complete ✅ $(Color_Off)

# ----------- Cleaning rules ---------- #

clean:
	$(MAKE) -C 42_lib clean
	$(MAKE) -C MLX42/build clean
	$(RM) $(OBJ_DIR)
	@echo $(Dark_Pink) Cleaning complete.. 💥 $(Color_Off)

fclean: clean
	$(MAKE) -C 42_lib fclean
	$(RM) $(NAME)
	@echo $(Dark_Pink) Thorough cleaning complete.. 💥 $(Color_Off)

re: fclean all

# ----------- Specific rules ---------- #

print-%:
	$(info '$*'='$($*)')

.PHONY: clean fclean re new all

# ----------- Color codes ---------- #

Color_Off	= "\033[0m"
Blue		= "\033[38;5;68m"
Yellow		= "\033[38;5;230m"
Pink		= "\033[38;5;218m"
Dark_Pink	= "\033[38;5;175m"
