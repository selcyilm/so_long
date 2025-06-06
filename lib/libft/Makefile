# **************************************************************************** #
#                                                                              #
#                                                          ::::::::            #
#    Makefile                                            :+:    :+:            #
#                                                       +:+                    #
#    By: selcyilm <marvin@42.fr>                       +#+                     #
#                                                     +#+                      #
#    Created: 2024/10/08 14:20:15 by selcyilm       #+#    #+#                 #
#    Updated: 2024/10/08 14:20:17 by selcyilm       ########   odam.nl         #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_striteri.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_tolower.c\
			ft_toupper.c\
			./get_next_line/get_next_line.c\
			./get_next_line/get_next_line_utils.c\


SRCS_BONUS	=	ft_lstadd_back_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstnew_bonus.c\
			ft_lstsize_bonus.c\
			ft_lstiter_bonus.c\
			ft_lstmap_bonus.c

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

NAME	=	libft.a
RM		=	rm -f
LIB		=	ar rcs
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

PRINTF	=	ft_printf/ft_printf.o\
			ft_printf/ft_strlen.o\
			ft_printf/print_digit.o\
			ft_printf/print_hex.o\
			ft_printf/print_ptr.o\
			ft_printf/print_str.o\
			ft_printf/print_unsigned.o

COLOUR_GREEN=\033[35m
COLOUR_BLUE=\033[0;36m
COLOUR_END=\033[0m
COLOUR_ORANGE=\033[38;5;214m

ifdef WITH_BONUS
	OBJ_SWITCH = $(OBJS_BONUS) $(OBJS)
else
	OBJ_SWITCH = $(OBJS)
endif

$(NAME)		:	$(PRINTF) $(OBJ_SWITCH)
			@$(LIB) $@ $^
			@echo "$(COLOUR_ORANGE)LIBFT.A IS READY TO GO$(COLOUR_END)"

$(PRINF)	:
			@make -C ./ft_printf

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(COLOUR_GREEN)CREATING $@$(COLOUR_END)"

all			:	bonus $(NAME)

clean		:
			@$(RM) $(OBJS) $(OBJS_BONUS)
			@make -s clean -C ./ft_printf
			@echo "$(COLOUR_BLUE)CLEARING OBJECT FILES FOR LIBFT$(COLOUR_END)"

fclean		:	clean
			@$(RM) $(NAME)
			@make -s fclean -C ./ft_printf
			@echo "$(COLOUR_BLUE)CLEANING EXECUTABLE FOR LIBFT...$(COLOUR_END)"

re		:	fclean all

bonus		:
			$(MAKE) WITH_BONUS=1 $(NAME)

.PHONY		:	all clean fclean re bonus
