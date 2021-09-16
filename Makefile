# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 10:00:43 by cmariot           #+#    #+#              #
#    Updated: 2021/09/16 17:15:23 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


ARG = 2 1 3 5 0 4


#### PUSH SWAP ###

PROGRAM = push_swap

PROGRAM_DIR = srcs

PROGRAM_SRCS_OBJS = ${PROGRAM_SRCS:.c=.o}

PROGRAM_SRCS = ${PROGRAM_DIR}/main.c \
			   ${PROGRAM_DIR}/put_in_stack.c \
			   ${PROGRAM_DIR}/sort_small_stacks.c \
			   ${PROGRAM_DIR}/radix.c \
			   ${PROGRAM_DIR}/swap_stacks.c \
			   ${PROGRAM_DIR}/push_stacks.c \
			   ${PROGRAM_DIR}/rotate_stacks.c \
			   ${PROGRAM_DIR}/reverse_rotate_stacks.c \
			   ${PROGRAM_DIR}/check_stacks.c


#### CHECKER ####
CHECKER = checker

CHECKER_DIR = bonus

CHECKER_SRCS_OBJS = ${CHECKER_SRCS:.c=.o}

CHECKER_SRCS = ${CHECKER_DIR}/main.c \
			   ${CHECKER_DIR}/put_in_stack_bonus.c \
			   ${CHECKER_DIR}/swap_stacks_bonus.c \
			   ${CHECKER_DIR}/push_stacks_bonus.c \
			   ${CHECKER_DIR}/rotate_stacks_bonus.c \
			   ${CHECKER_DIR}/reverse_rotate_stacks_bonus.c \
			   ${CHECKER_DIR}/check_stacks_bonus.c


COMPILER = gcc

COMPILER_FLAGS = -Wall -Wextra -Werror

INCLUDES_DIR = includes

LIBFT_DIR = libft

REMOVE = rm -rf


..c.o:
				${COMPILER} ${COMPILER_FLAGS} -g -c $< -o ${<:.c=.o} -I ${INCLUDES_DIR} -I ${LIBFT_DIR}


${PROGRAM}:		program_compil


program_compil: compil_libft ${PROGRAM_SRCS_OBJS}
				${COMPILER} ${COMPILER_FLAGS} ${PROGRAM_SRCS_OBJS} -I ${INCLUDES_DIR} -L ${LIBFT_DIR} -lft -o ${PROGRAM}
				@printf "The push_swap program is ready.\n"


random_500:
				@echo `seq -250 249 | sort -R | tr "\n" " "`

random_100:
				@echo `seq 0 100 | sort -R | tr "\n" " "`

random_5:
				@echo `seq 0 5 | sort -R | tr "\n" " "` 

random_3:
				@echo `seq 0 3 | sort -R | tr "\n" " "` 


test:			program_compil
				./${PROGRAM} ${ARG}

count:			checker_compil
				@printf "Total number of instructions : "
				@./${PROGRAM} ${ARG} | wc -l

program_leaks:	program_compil
				valgrind ./${PROGRAM} ${ARG}


${CHECKER}:		checker_compil

checker_compil:	compil_libft ${CHECKER_SRCS_OBJS}
				${COMPILER} ${COMPILER_FLAGS} ${CHECKER_SRCS_OBJS} -I ${INCLUDES_DIR} -L ${LIBFT_DIR} -lft -g -o ${CHECKER}
				@printf "The checker is ready.\n"

checker_test:	program_compil checker_compil
				./push_swap ${ARG} | ./${CHECKER} ${ARG}

checker_leaks:	checker_compil
				valgrind ./${CHECKER} ${ARG}

leaks:			program_compil checker_compil
				valgrind --leak-check=full ./${PROGRAM} ${ARG} | ./${CHECKER} ${ARG}

all: 			program_compil checker_compil

bonus:			all

norme:
				norminette ./srcs ./includes ./libft ./bonus
				@printf "The norm is checked in this directory and all subdirectories.\n"

compil_libft:
				cd ${LIBFT_DIR} && make

clean:
				@cd libft && make clean
				${REMOVE} ${PROGRAM_SRCS_OBJS}
				${REMOVE} ${CHECKER_SRCS_OBJS}
				@printf "The object files have been deleted.\n"

fclean:			
				@cd libft && make fclean
				${REMOVE} ${PROGRAM_SRCS_OBJS}
				${REMOVE} ${CHECKER_SRCS_OBJS}
				${REMOVE} ${PROGRAM}
				${REMOVE} ${CHECKER}
				@printf "The object and binary files have been deleted.\n"

re:				fclean all

.PHONY:			clean fclean
