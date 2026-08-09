NAME		= libunit.a

MAKEFLAGS	+= --no-print-directory

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

TESTS_DIR	= tests
BONUS_DIR	= tests/bonus
REAL_DIR	= real-tests

INCLUDES	= -Iframework

COMMON_SRCS	= framework/load_test.c \
			  framework/ft_printf.c \
			  framework/ft_printf_put.c

SRCS		= $(COMMON_SRCS) \
			  framework/launch_tests.c \
			  framework/status.c

BONUS_SRCS	= $(COMMON_SRCS) \
			  framework/launch_tests_bonus.c \
			  framework/status_bonus.c \
			  framework/log_bonus.c \
			  framework/log_open_bonus.c

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

all: .mandatory

bonus: .bonus

.mandatory: $(OBJS)
	@$(RM) $(NAME) .bonus
	@$(AR) $(NAME) $(OBJS)
	@touch .mandatory

.bonus: $(BONUS_OBJS)
	@$(RM) $(NAME) .mandatory
	@$(AR) $(NAME) $(BONUS_OBJS)
	@touch .bonus

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test: all
	@$(MAKE) -C $(TESTS_DIR) test
	@$(MAKE) -C $(REAL_DIR) test
	@$(MAKE) clean

test_bonus: bonus
	@$(MAKE) -C $(BONUS_DIR) test
	@$(MAKE) -C $(REAL_DIR) test
	@$(MAKE) clean

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(TESTS_DIR) clean
	@$(MAKE) -C $(BONUS_DIR) clean
	@$(MAKE) -C $(REAL_DIR) clean

fclean: clean
	@$(RM) $(NAME) .mandatory .bonus
	@$(MAKE) -C $(TESTS_DIR) fclean
	@$(MAKE) -C $(BONUS_DIR) fclean
	@$(MAKE) -C $(REAL_DIR) fclean

re: fclean all

.PHONY: all bonus test test_bonus clean fclean re
