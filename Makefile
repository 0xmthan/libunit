NAME		= libunit.a

MAKEFLAGS	+= --no-print-directory

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

TESTS_DIR	= tests
REAL_DIR	= real-tests

INCLUDES	= -Iframework

SRCS		= framework/load_test.c \
			  framework/launch_tests.c \
			  framework/ft_printf.c \
			  framework/ft_printf_put.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test: $(NAME)
	@$(MAKE) -C $(TESTS_DIR) test
	@$(MAKE) -C $(REAL_DIR) test
	@$(MAKE) clean

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(TESTS_DIR) clean
	@$(MAKE) -C $(REAL_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(TESTS_DIR) fclean
	@$(MAKE) -C $(REAL_DIR) fclean

re: fclean all

.PHONY: all test clean fclean re
