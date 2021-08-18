# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 10:00:43 by cmariot           #+#    #+#              #
#    Updated: 2021/08/18 16:30:38 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAM = push_swap

PROGRAM_DIR = srcs

PROGRAM_SRCS = ${PROGRAM_DIR}/main.c \
			   ${CHECKER_DIR}/put_in_stack.c \
			   ${PROGRAM_DIR}/swap_stacks.c \
			   ${PROGRAM_DIR}/push_stacks.c \
			   ${PROGRAM_DIR}/rotate_stacks.c \
			   ${PROGRAM_DIR}/reverse_rotate_stacks.c \
			   ${PROGRAM_DIR}/radix.c \
			   ${CHECKER_DIR}/swap_stacks.c \
			   ${CHECKER_DIR}/push_stacks.c \
			   ${CHECKER_DIR}/rotate_stacks.c \
			   ${CHECKER_DIR}/reverse_rotate_stacks.c \
			   ${CHECKER_DIR}/check_stacks.c

PROGRAM_SRCS_OBJS = ${PROGRAM_SRCS:.c=.o}

CHECKER = checker

CHECKER_DIR = bonus

CHECKER_SRCS = ${CHECKER_DIR}/main.c \
			   ${CHECKER_DIR}/put_in_stack.c \
			   ${CHECKER_DIR}/swap_stacks.c \
			   ${CHECKER_DIR}/push_stacks.c \
			   ${CHECKER_DIR}/rotate_stacks.c \
			   ${CHECKER_DIR}/reverse_rotate_stacks.c \
			   ${CHECKER_DIR}/check_stacks.c

CHECKER_SRCS_OBJS = ${CHECKER_SRCS:.c=.o}

INCLUDES_DIR = includes

LIBFT_DIR = libft

LIBFT_LIB = libft/libft.a

COMPILER = gcc

COMPILER_FLAGS = -Wall -Wextra -Werror

REMOVE = rm -rf

.c.o:
				${COMPILER} ${COMPILER_FLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES_DIR} -I ${LIBFT_DIR}

${PROGRAM}:		program_compil

${CHECKER}:		checker_compil

all: 			program_compil checker_compil

bonus:			program_compil checker_compil

norme:
				norminette ./srcs ./includes ./libft ./bonus
				@printf "\x1b[32mThe norm is checked in this directory and all subdirectories.\x1b[0m\n"

compil_libft:
				cd ${LIBFT_DIR} && make

program_compil: compil_libft ${PROGRAM_SRCS_OBJS}
				${COMPILER} ${COMPILER_FLAGS} ${PROGRAM_SRCS_OBJS} -I ${INCLUDES_DIR} -L ${LIBFT_DIR} -lft -o ${PROGRAM}
				@printf "\x1b[32mpush_swap is ready.\x1b[0m\n"

test:			program_compil
				./${PROGRAM} 1 2

program_leaks:	program_compil
				leaks -atExit -- ./${PROGRAM} 1 2 3 4 5

checker_compil:	compil_libft ${CHECKER_SRCS_OBJS}
				${COMPILER} ${COMPILER_FLAGS} ${CHECKER_SRCS_OBJS} -I ${INCLUDES_DIR} -L ${LIBFT_DIR} -lft -o ${CHECKER}
				@printf "\x1b[32mThe checker is ready.\x1b[0m\n"

checker_test:	checker_compil
				./${CHECKER} 1 2 3 4 5

checker_leaks:	checker_compil
				leaks -atExit -- ./${CHECKER} 1 2 3 4 5

clean:
				cd libft && make clean
				${REMOVE} ${PROGRAM_SRCS_OBJS}
				${REMOVE} ${CHECKER_SRCS_OBJS}
				@printf "\x1b[32mThe object files have been deleted\x1b[0m\n"

fclean:			
				cd libft && make fclean
				${REMOVE} ${PROGRAM_SRCS_OBJS}
				${REMOVE} ${CHECKER_SRCS_OBJS}
				${REMOVE} ${PROGRAM}
				${REMOVE} ${CHECKER}
				@printf "\x1b[32mThe object and binary files have been deleted\x1b[0m\n"

re:				fclean all

.PHONY:			clean fclean
