NAME := cub3d

OS 	 := $(shell uname)

ifneq (,$(findstring xterm,${TERM}))
	BLACK        := $(shell tput -Txterm setaf 0)
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
	PURPLE       := $(shell tput -Txterm setaf 5)
	BLUE         := $(shell tput -Txterm setaf 6)
	WHITE        := $(shell tput -Txterm setaf 7)
	RESET 		 := $(shell tput -Txterm sgr0)
else
	BLACK        := ""
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	LIGHTPURPLE  := ""
	PURPLE       := ""
	BLUE         := ""
	WHITE        := ""
	RESET        := ""
endif

SRC_MAIN = 	main.c \
			src/init/checks.c \
			src/init/checks2.c \
			src/init/init.c \
			src/init/readcub.c \
			src/init/readcub2.c \
			src/init/player.c \
			src/init/init_colors_images.c \
			src/init/rgb.c \
			src/handlers/keyevents.c \
			src/handlers/movement.c \
			src/handlers/movement2.c \
			src/handlers/boundary.c \
			src/loop/loop.c \
			src/loop/minimap_buffer.c \
			src/loop/minimap_buffer2.c \
			src/loop/raycast_buffer.c \
			src/loop/raycast_buffer2.c \
			src/loop/bresenhams.c \
			src/loop/dda.c \
			src/loop/dda2.c \
			src/loop/calibration.c \
			src/utils/point_math.c \
			src/utils/free_exit.c \
			src/utils/time.c \
			src/utils/printers.c \
			src/utils/math.c \
			src/utils/else.c \

SRC	= $(SRC_MAIN) 

FLAGS				:= -g -Wall -Wextra -Werror -fcommon -O3
MINI_FLAG			:= -Imlx

OBJS				= $(addprefix $(OBJS_DIR)/, ${SRC:.c=.o})
LIBFT				= $(addprefix $(LIBF_DIR), $(LIBFT_A))
MLX_DIR				= $(addprefix $(MLX_DIR), $(MLX_LIB))
# OBJS PREPARATIONS
OBJS_DIR			= objs

# LIBRARIES 
LIBFT_DIR	:= libft/
LIBFT_A		:= libft/libft.a

MLX_DIR		:= minilibx/
MLX_LIB		= libmlx.dylib

LIBFT_MAKE	:= @cd libft && make --no-print-directory && make clean --no-print-directory
MLX_MAKE	:= @cd minilibx && make -s CFLAGS="-Wno-error=format-truncation" --no-print-directory 2> /dev/null && mv libmlx.dylib .. && make clean --no-print-directory > /dev/null
			

RMLIB		:= @cd libft && make fclean --no-print-directory
RMMLX		:= @cd ${MLX_DIR} && make fclean --no-print-directory

CC	= @gcc

DEBUG_F	= -g -fsanitize=address

RACE_F	= -g -fsanitize=thread

LEAK_F  = -g -fsanitize=leak -llsan

$(NAME): $(OBJS)
	@echo "	... [Making libft]"
	@$(LIBFT_MAKE)
	@echo "		${GREEN}Libft compiled${RESET}"
	@echo "	... [Making Minilibx]"
	@$(MLX_MAKE)
	@echo "		${GREEN}Minilibx compiled${RESET}"
	@echo "	... [Making $(NAME)]"
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT_A) ${MLX_LIB} -o $(NAME) > /dev/null
	@echo "		${GREEN}Cub3d compiled${RESET}"
#	@echo " [Compiled]"

# LINK ALL OBJECTS
$(shell echo $(OBJS_DIR))/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	@echo "	... [Removing ${NAME} objs files]"
	@rm   -rf ${OBJS_DIR}
	@echo "		${RED} ${NAME} OBJS deleted${RESET}"

fclean: clean
	@rm -rf *.dylib
	@cd minilibx && make clean > /dev/null
	@echo "	... [Removing $(NAME)]"
	@rm -rf ${NAME}
	@echo "		${RED}*.a's deleted${RESET}"
	$(RMLIB)

clean_all: fclean
	$(RMLIB)

# minilibx: $(MLX_MAKE)

norm:
	norminette -R CheckForbiddenSourceHeader *.c *.h src/*/*.c src/*/*.h libft/*.c libft/*.h

sanitize:	re $(OBJS)
			@$(CC) $(DEBUG_F) $(OBJS) $(LIBFT_A) ${MLX_LIB} -o $(NAME)
			$(info [Making with fsanitize=address ...])

race:		re $(OBJS)
			@$(CC) $(RACE_F) $(OBJS) $(LIBFT_A) ${MLX_LIB} -o $(NAME)
			$(info [Making with fsanitize=thread ...])

leak:		re $(OBJS)
			@$(CC) $(LEAK_F) $(OBJS) $(LIBFT_A) ${MLX_LIB} -o $(NAME)
			$(info [Making with fsanitize=leak ...])

re: 		fclean $(NAME)

ree:		clean_all $(NAME)

.PHONY : all clean fclean re
.SILENT: minilibx
