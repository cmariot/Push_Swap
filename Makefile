# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 10:00:43 by cmariot           #+#    #+#              #
#    Updated: 2021/09/12 14:28:10 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
PROGRAM = push_swap

# Argument for testing
ARG = 7933 3404 9369 8273 4231

# push_swap source directory
PROGRAM_DIR = srcs

# push_swap source files
PROGRAM_SRCS = ${PROGRAM_DIR}/main.c \
			   ${PROGRAM_DIR}/put_in_stack.c \
			   ${PROGRAM_DIR}/swap_stacks.c \
			   ${PROGRAM_DIR}/push_stacks.c \
			   ${PROGRAM_DIR}/rotate_stacks.c \
			   ${PROGRAM_DIR}/reverse_rotate_stacks.c \
			   ${PROGRAM_DIR}/sort_small_stacks.c \
			   ${PROGRAM_DIR}/radix.c \
			   ${PROGRAM_DIR}/swap_stacks_bonus.c \
			   ${PROGRAM_DIR}/push_stacks_bonus.c \
			   ${PROGRAM_DIR}/rotate_stacks_bonus.c \
			   ${PROGRAM_DIR}/reverse_rotate_stacks_bonus.c \
			   ${PROGRAM_DIR}/check_stacks.c

# push_swap object files
PROGRAM_SRCS_OBJS = ${PROGRAM_SRCS:.c=.o}

# checker name
CHECKER = checker

# checker source directory
CHECKER_DIR = bonus

# checker source files
CHECKER_SRCS = ${CHECKER_DIR}/main.c \
			   ${CHECKER_DIR}/put_in_stack_bonus.c \
			   ${CHECKER_DIR}/swap_stacks_bonus.c \
			   ${CHECKER_DIR}/push_stacks_bonus.c \
			   ${CHECKER_DIR}/rotate_stacks_bonus.c \
			   ${CHECKER_DIR}/reverse_rotate_stacks_bonus.c \
			   ${CHECKER_DIR}/check_stacks_bonus.c

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
				${COMPILER} ${COMPILER_FLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES_DIR} -I ${LIBFT_DIR}

# Push_swap rules
# Alias for compilation
${PROGRAM}:		program_compil

# Push_swap's compilation
program_compil: compil_libft ${PROGRAM_SRCS_OBJS}
				${COMPILER} ${COMPILER_FLAGS} ${PROGRAM_SRCS_OBJS} -I ${INCLUDES_DIR} -L ${LIBFT_DIR} -lft -g -o ${PROGRAM}
				@printf "The push_swap program is ready.\n"

# Test push_swap with the arguments given at the top of Makefile
test:			program_compil
				./${PROGRAM} ${ARG}

# Count the push_swap outpout number of lines 
count:			checker_compil
				@printf "Total number of instructions : "
				@./${PROGRAM} ${ARG} | wc -l

# Check leaks on push_swap with the arguments given at the top of Makefile
program_leaks:	program_compil
				valgrind ./${PROGRAM} ${ARG}


# Checker rules
# Alias for compilation
${CHECKER}:		checker_compil

# Checker's compilation
checker_compil:	compil_libft ${CHECKER_SRCS_OBJS}
				${COMPILER} ${COMPILER_FLAGS} ${CHECKER_SRCS_OBJS} -I ${INCLUDES_DIR} -L ${LIBFT_DIR} -lft -g -o ${CHECKER}
				@printf "The checker is ready.\n"

# Test push_swap & checker with the arguments given at the top of Makefile
checker_test:	program_compil checker_compil
				./push_swap ${ARG} | ./${CHECKER} ${ARG}

# Check leaks on checker with the arguments given at the top of Makefile
checker_leaks:	checker_compil
				valgrind ./${CHECKER} ${ARG}


# Both rules
all: 			program_compil checker_compil
bonus:			all

# Check the norme in the source directories
norme:
				norminette ./srcs ./includes ./libft ./bonus
				@printf "The norm is checked in this directory and all subdirectories.\n"

# Libft compilation
compil_libft:
				cd ${LIBFT_DIR} && make

# Delete the .o files
clean:
				@cd libft && make clean
				${REMOVE} ${PROGRAM_SRCS_OBJS}
				${REMOVE} ${CHECKER_SRCS_OBJS}
				@printf "The object files have been deleted.\n"

# Delete the .o .a and exec files
fclean:			
				@cd libft && make fclean
				${REMOVE} ${PROGRAM_SRCS_OBJS}
				${REMOVE} ${CHECKER_SRCS_OBJS}
				${REMOVE} ${PROGRAM}
				${REMOVE} ${CHECKER}
				@printf "The object and binary files have been deleted.\n"

# Delete all and redo
re:				fclean all

.PHONY:			clean fclean
