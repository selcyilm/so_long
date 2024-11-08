NAME	= so_long
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g
CC		= cc
LIBMLX	= ./lib/MLX42
LIBFT	= ./lib/libft/libft.a
HEADERS	= -I ./lib/libft/ -I ./include -I $(LIBMLX)/include/
LIBS	= $(LIBMLX)/build/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm
SRCS	=	./src/main.c \
			./src/file_utils.c \
			./src/error.c \
			./src/map_validation.c \
			./src/valid_path_check.c \


OBJS	= $(SRCS:.c=.o)

#-----------------ASCI TEXT------------------#
define ASCII_TEXT
  ____     ___      _        ___    _   _    ____ 
 / ___|   / _ \    | |      / _ \  | \ | |  / ___|
 \___ \  | | | |   | |     | | | | |  \| | | |  _ 
  ___| | | |_| |   | |___  | |_| | | |\  | | |_| |
 |____/   \___/    |_____|  \___/  |_| \_|  \____|
                                                  
endef

export ASCII_TEXT
#-----------------ASCI TEXT END--------------#
# ANSI color codes
CYAN = \033[36m
RESET = \033[0m
COLOUR_GREEN=\033[35m
COLOUR_BLUE=\033[0;36m
COLOUR_ORANGE=\033[38;5;214m

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(MAKE) -s -C ./lib/libft all
	@$(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$(CYAN)$$ASCII_TEXT$(RESET)"
	@echo "\n$(COLOUR_ORANGE)Usage:$(RESET) $(COLOUR_GREEN)./so_long$(RESET) $(CYAN)<[map-file].ber>$(RESET)"
	@echo "$(COLOUR_ORANGE)Let's Get Ready To Rumble!$(RESET)"

clean:
	@$(MAKE) -s -C lib/libft/ clean
	@rm -rf $(LIBMLX)/build
	@rm -rf $(OBJS)
	@echo "$(COLOUR_BLUE)CLEANING OBJECT FILES FOR SO_LONG..$(RESET)"

fclean: clean
	@$(MAKE) -s -C lib/libft/ fclean
	@rm -rf $(NAME)
	@echo "$(COLOUR_BLUE)CLEANING EXECUTABLE FOR SO_LONG..$(RESET)"

test:
	$(CC) $(CFLAGS) tests/*.c -lcriterion $(LIBFT) include/so_long.h -o test_result

re: clean all

.PHONY: all, clean, fclean, re, libmlx