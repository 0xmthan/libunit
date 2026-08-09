NAME		= test_bonus

MAKEFLAGS	+= --no-print-directory

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

ROOT_DIR	= ../..
LIBUNIT		= $(ROOT_DIR)/libunit.a

INCLUDES	= -I$(ROOT_DIR)/framework

SIGNALS		= signals/00_launcher_bonus.c \
			  signals/01_sigabrt_test_bonus.c \
			  signals/02_sigfpe_test_bonus.c \
			  signals/03_sigpipe_test_bonus.c \
			  signals/04_sigill_test_bonus.c

TIMEOUT		= timeout/00_launcher_bonus.c \
			  timeout/01_infinite_loop_test_bonus.c

OUTPUT		= output/00_launcher_bonus.c \
			  output/01_write_test_bonus.c \
			  output/02_capture_test_bonus.c

LOGS		= log/00_launcher_bonus.c \
			  log/01_write_test_bonus.c \
			  log/02_header_test_bonus.c \
			  log/03_content_test_bonus.c \
			  log/04_status_test_bonus.c

COLOR		= color/00_launcher_bonus.c \
			  color/01_ok_test_bonus.c \
			  color/02_ko_test_bonus.c \
			  color/03_signal_test_bonus.c \
			  color/04_timeout_test_bonus.c \
			  color/05_plain_log_test_bonus.c

SRCS		= main_bonus.c \
			  utils_bonus.c \
			  $(SIGNALS) \
			  $(TIMEOUT) \
			  $(OUTPUT) \
			  $(LOGS) \
			  $(COLOR)

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
