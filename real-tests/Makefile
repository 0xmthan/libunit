NAME		= test_real
MAKEFLAGS	+= --no-print-directory

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

ROOT_DIR	= ..
LIBUNIT		= $(ROOT_DIR)/libunit.a

INCLUDES	= -I$(ROOT_DIR)/framework \
			  -Iget_next_line/gnl

SRCS		= main.c \
			  $(wildcard */*.c) \
			  $(wildcard */*/*.c)

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBUNIT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBUNIT) -o $(NAME)

$(LIBUNIT):
	@$(MAKE) -C $(ROOT_DIR)

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
