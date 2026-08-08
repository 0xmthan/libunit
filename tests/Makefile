NAME		= test_demo

MAKEFLAGS	+= --no-print-directory

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

ROOT_DIR	= ..
LIBUNIT		= $(ROOT_DIR)/libunit.a
LIBFT		= $(ROOT_DIR)/libft/libft.a

INCLUDES	= -I$(ROOT_DIR)/framework -I$(ROOT_DIR)/libft

SRCS		= main.c $(wildcard */*.c)
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBUNIT) $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBUNIT) $(LIBFT) -o $(NAME)

$(LIBUNIT):
	@$(MAKE) -C $(ROOT_DIR)

$(LIBFT):
	@$(MAKE) -C $(ROOT_DIR)/libft

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test: all
	@./$(NAME) || true

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all test clean fclean re
