# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 10:00:43 by cmariot           #+#    #+#              #
#    Updated: 2021/08/11 17:13:14 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker

CHECKER_DIR = bonus

COMPILER = gcc

COMPILER_FLAGS = -Wall -Wextra -Werror

INCLUDES_DIR = includes

LIBFT_DIR = libft

CHECKER_SRCS = ${CHECKER_DIR}/main.c \
			   ${CHECKER_DIR}/swap_stacks.c \
			   ${CHECKER_DIR}/reverse_reverse_stacks.c \
			   ${CHECKER_DIR}/reverse_stacks.c \
			   ${CHECKER_DIR}/check_stacks.c

CHECKER_SRCS_OBJS = ${CHECKER_SRCS:.c=.o}

LIBFT_LIB = libft/libft.a

REMOVE = rm -rf

MAIN = main.c

.c.o:
				${COMPILER} ${COMPILER_FLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES_DIR} -I ${LIBFT_DIR}

${CHECKER}:		checker_compil

all: 			checker_compil

bonus:			checker_compil

norme:
				norminette ./srcs ./includes ./libft ./bonus
				@printf "\x1b[32mThe norm is checked in this directory and all subdirectories.\x1b[0m\n"

compil_libft:
				cd ${LIBFT_DIR} && make

checker_compil:	compil_libft ${CHECKER_SRCS_OBJS}
				${COMPILER} ${COMPILER_FLAGS} ${CHECKER_SRCS_OBJS} -I ${INCLUDES_DIR} -L ${LIBFT_DIR} -lft -o ${CHECKER}
				@printf "\x1b[32mThe checker is ready.\x1b[0m\n"

checker_test:	checker_compil
				./${CHECKER} 1 2 3 4 5

checker_leaks:	checker_compil
				leaks -atExit -- ./${CHECKER} 1 2 3 4 5

clean:
				cd libft && make clean
				${REMOVE} ${CHECKER_SRCS_OBJS}
				@printf "\x1b[32mThe object files have been deleted\x1b[0m\n"

fclean:			
				cd libft && make fclean
				${REMOVE} ${CHECKER_SRCS_OBJS}
				${REMOVE} ${CHECKER}
				@printf "\x1b[32mThe object and binary files have been deleted\x1b[0m\n"

re:				fclean all

.PHONY:			clean fclean

