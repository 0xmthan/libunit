NAME		= libunit.a

MAKEFLAGS	+= --no-print-directory

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

TESTS_DIR	= tests
REAL_DIR	= real-tests

INCLUDES	= -Iframework -I$(LIBFT_DIR)

SRCS		= framework/load_test.c \
			  framework/launch_tests.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(AR) $(NAME) $(OBJS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

test: $(NAME)
	@$(MAKE) -C $(TESTS_DIR) test
	@$(MAKE) -C $(REAL_DIR) test

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(TESTS_DIR) clean
	@$(MAKE) -C $(REAL_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(TESTS_DIR) fclean
	@$(MAKE) -C $(REAL_DIR) fclean

re: fclean all

.PHONY: all test clean fclean re
