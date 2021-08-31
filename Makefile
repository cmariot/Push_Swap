# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 10:00:43 by cmariot           #+#    #+#              #
#    Updated: 2021/08/27 23:11:36 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
PROGRAM = push_swap

# Argument for testing
ARG = 5 2 1 3 4

# push_swap source directory
PROGRAM_DIR = srcs

# push_swap source files
PROGRAM_SRCS = ${PROGRAM_DIR}/main.c \
			   ${CHECKER_DIR}/put_in_stack.c \
			   ${PROGRAM_DIR}/swap_stacks.c \
			   ${PROGRAM_DIR}/push_stacks.c \
			   ${PROGRAM_DIR}/rotate_stacks.c \
			   ${PROGRAM_DIR}/reverse_rotate_stacks.c \
			   ${PROGRAM_DIR}/sort_small_stacks.c \
			   ${PROGRAM_DIR}/radix.c \
			   ${CHECKER_DIR}/swap_stacks.c \
			   ${CHECKER_DIR}/push_stacks.c \
			   ${CHECKER_DIR}/rotate_stacks.c \
			   ${CHECKER_DIR}/reverse_rotate_stacks.c \
			   ${CHECKER_DIR}/check_stacks.c

# push_swap object files
PROGRAM_SRCS_OBJS = ${PROGRAM_SRCS:.c=.o}

# checker name
CHECKER = checker

# checker source directory
CHECKER_DIR = bonus

# checker source files
CHECKER_SRCS = ${CHECKER_DIR}/main.c \
			   ${CHECKER_DIR}/put_in_stack.c \
			   ${CHECKER_DIR}/swap_stacks.c \
			   ${CHECKER_DIR}/push_stacks.c \
			   ${CHECKER_DIR}/rotate_stacks.c \
			   ${CHECKER_DIR}/reverse_rotate_stacks.c \
			   ${CHECKER_DIR}/check_stacks.c

# checker object files
CHECKER_SRCS_OBJS = ${CHECKER_SRCS:.c=.o}

# Header directory 
INCLUDES_DIR = includes

# Libft source directory
LIBFT_DIR = libft

COMPILER = gcc

COMPILER_FLAGS = -Wall -Wextra -Werror

REMOVE = rm -rf

# Convert .c files into .o files
.c.o:
				@${COMPILER} ${COMPILER_FLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES_DIR} -I ${LIBFT_DIR}


# Push_swap rules
# Alias for compilation
${PROGRAM}:		program_compil

# Push_swap's compilation
program_compil: compil_libft ${PROGRAM_SRCS_OBJS}
				@${COMPILER} ${COMPILER_FLAGS} ${PROGRAM_SRCS_OBJS} -I ${INCLUDES_DIR} -L ${LIBFT_DIR} -lft -o ${PROGRAM}
				@printf "\x1b[32mThe push_swap program is ready.\x1b[0m\n"

# Test push_swap with the arguments given at the top of Makefile
test:			program_compil
				./${PROGRAM} ${ARG}

# Count the push_swap outpout number of lines 
count:			checker_compil
				@printf "\x1b[32mTotal number of instructions : \x1b[0m"
				@./${PROGRAM} ${ARG} | wc -l

# Check leaks on push_swap with the arguments given at the top of Makefile
program_leaks:	program_compil
				leaks -atExit -- ./${PROGRAM} ${ARG}


# Checker rules
# Alias for compilation
${CHECKER}:		checker_compil

# Checker's compilation
checker_compil:	compil_libft ${CHECKER_SRCS_OBJS}
				@${COMPILER} ${COMPILER_FLAGS} ${CHECKER_SRCS_OBJS} -I ${INCLUDES_DIR} -L ${LIBFT_DIR} -lft -o ${CHECKER}
				@printf "\x1b[32mThe checker is ready.\x1b[0m\n"

# Test push_swap & checker with the arguments given at the top of Makefile
checker_test:	checker_compil
				./push_swap ${ARG} | ./${CHECKER} ${ARG}

# Check leaks on checker with the arguments given at the top of Makefile
checker_leaks:	checker_compil
				leaks -atExit -- ./${CHECKER} ${ARG}


# Both rules
all: 			program_compil checker_compil
bonus:			all

# Check the norme in the source directories
norme:
				norminette ./srcs ./includes ./libft ./bonus
				@printf "\x1b[32mThe norm is checked in this directory and all subdirectories.\x1b[0m\n"

# Libft compilation
compil_libft:
				@cd ${LIBFT_DIR} && make

# Delete the .o files
clean:
				@cd libft && make clean
				@${REMOVE} ${PROGRAM_SRCS_OBJS}
				@${REMOVE} ${CHECKER_SRCS_OBJS}
				@printf "\x1b[32mThe object files have been deleted.\x1b[0m\n"

# Delete the .o .a and exec files
fclean:			
				@cd libft && make fclean
				@${REMOVE} ${PROGRAM_SRCS_OBJS}
				@${REMOVE} ${CHECKER_SRCS_OBJS}
				@${REMOVE} ${PROGRAM}
				@${REMOVE} ${CHECKER}
				@printf "\x1b[32mThe object and binary files have been deleted.\x1b[0m\n"

# Delete all and redo
re:				fclean all

.PHONY:			clean fclean
