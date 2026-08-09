NAME		= test_bonus

MAKEFLAGS	+= --no-print-directory

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

ROOT_DIR	= ../..
LIBUNIT		= $(ROOT_DIR)/libunit.a

INCLUDES	= -I$(ROOT_DIR)/framework

SRCS		= main_bonus.c \
			  00_launcher_bonus.c \
			  01_utils_bonus.c \
			  02_signals_test_bonus.c \
			  03_timeout_test_bonus.c \
			  04_stdout_test_bonus.c \
			  05_log_test_bonus.c \
			  06_color_test_bonus.c

OBJS		= $(SRCS:.c=.o)
LOG			= *.log

all: $(NAME)

$(NAME): $(LIBUNIT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBUNIT) -o $(NAME)

$(LIBUNIT):
	@$(MAKE) -C $(ROOT_DIR) bonus

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test: all
	@$(RM) $(LOG)
	@./$(NAME) || true

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME) $(LOG)

re: fclean all

.PHONY: all test clean fclean re
