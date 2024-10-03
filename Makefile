# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 15:29:59 by gmunoz            #+#    #+#              #
#    Updated: 2024/10/03 16:54:10 by gmunoz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Leak check
LEAKS =  valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all

# Executable name
NAME = pipex

# Libft
LIBFT = ./Libft/libft.a

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra

# Source files
SRC = src/pipex.c src/pipex_utils.c

# Object files
OBJS = $(SRC:.c=.o)

# Default NAME
all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -j -C Libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Link object files into the executable
$(NAME): $(OBJS)

# Clean up generated files
clean:
	$(MAKE) fclean -C Libft
	rm -f $(OBJS)

# Clean up everything
fclean: clean
	rm -f $(NAME)

# Re-compile everything
re: fclean
	make all

.PHONY: all clean fclean re