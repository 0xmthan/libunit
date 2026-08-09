NAME		= test_demo

MAKEFLAGS	+= --no-print-directory

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

ROOT_DIR	= ..
LIBUNIT		= $(ROOT_DIR)/libunit.a

INCLUDES	= -I$(ROOT_DIR)/framework

SRCS		= main.c \
			  demo/00_launcher.c \
			  demo/01_ok_test.c \
			  demo/02_ko_test.c \
			  demo/03_segv_test.c \
			  demo/04_bus_test.c \
			  demo/demo.c \
			  bonus/log/00_launcher.c \
			  bonus/log/01_log_test.c \
			  bonus/signals/00_launcher.c \
			  bonus/signals/01_sigabrt_test.c \
			  bonus/signals/02_sigfpe_test.c \
			  bonus/signals/03_sigpipe_test.c \
			  bonus/signals/04_sigill_test.c \
			  bonus/stdout/00_launcher.c \
			  bonus/stdout/01_stdout_test.c \
			  bonus/timeout/00_launcher.c \
			  bonus/timeout/01_timeout_test.c

OBJS		= $(SRCS:.c=.o)
LOG			= *.log

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
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all test clean fclean re
