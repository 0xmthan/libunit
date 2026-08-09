NAME        = test_real
MAKEFLAGS   += --no-print-directory

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

ROOT_DIR    = ..
LIBUNIT     = $(ROOT_DIR)/libunit.a

INCLUDES    = -I$(ROOT_DIR)/framework \
              -Iget_next_line/gnl

SRCS        = main.c \
              get_next_line/00_launcher.c \
              get_next_line/01_basic_test.c \
              get_next_line/02_empty_test.c \
              get_next_line/03_invalid_fd_test.c \
              get_next_line/04_exact_buffer_test.c \
              get_next_line/05_newline_test.c \
              get_next_line/06_no_newline_test.c \
              get_next_line/07_two_lines_test.c \
              get_next_line/08_long_line_test.c \
              get_next_line/09_long_no_newline_test.c \
              get_next_line/10_eof_test.c \
              get_next_line/11_long_then_short_test.c \
              get_next_line/12_only_newlines_test.c \
              get_next_line/13_buffer_edge_test.c \
              get_next_line/14_mixed_lengths_test.c \
              get_next_line/15_many_lines_test.c \
              get_next_line/ft_strcmp.c \
              get_next_line/gnl/get_next_line.c \
              get_next_line/gnl/get_next_line_utils.c

OBJS        = $(SRCS:.c=.o)
LOG         = libunit.log

all: $(NAME)

$(NAME): $(LIBUNIT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBUNIT) -o $(NAME)

$(LIBUNIT):
	@$(MAKE) -C $(ROOT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test: all
	@$(RM) $(LOG)
	@./$(NAME) || true

clean:
	@$(RM) $(OBJS) $(LOG)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all test clean fclean re
