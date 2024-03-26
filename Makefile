# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC = $(wildcard *.c)

# Object files
OBJS = $(SRC:.c=.o)

# Name of the executable
NAME = exe.out

# Main rule to build the executable
all: $(NAME)

# Compile object files from source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Clean up object files
clean:
	rm -f $(OBJS)

# Full cleanup including executable
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

# Ensure that 'all', 'clean', 'fclean', 're', and 'bonus' are not interpreted as file names
.PHONY: all clean fclean re