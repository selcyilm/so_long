NAME	= so_long
CFLAGS	= -Wextra -Wall -Werror
CC		= cc
LIBMLX	= ./lib/MLX42
LIBFT	= ./lib/libft/libft.a
HEADERS	= -I ./lib/libft/ -I $(LIBMLX)/include/
LIBS	= $(LIBMLX)/build/libmlx42.a -Iinclude -lglfw
SRCS	= ./src/main.c \

OBJS	= $(SRCS:.c=.o)

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(MAKE) -C ./lib/libft
	@$(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@$(MAKE) -s -C lib/libft/ clean
	@rm -rf $(LIBMLX)/build
	@rm -rf $(OBJS)

fclean: clean
	@$(MAKE) -s -C lib/libft/ fclean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx