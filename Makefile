# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 10:00:43 by cmariot           #+#    #+#              #
#    Updated: 2021/09/18 12:26:08 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#### PUSH SWAP ###

PROGRAM = push_swap

PROGRAM_DIR = srcs

PROGRAM_SRCS_OBJS = ${PROGRAM_SRCS:.c=.o}

PROGRAM_SRCS = ${PROGRAM_DIR}/main.c \
			   ${PROGRAM_DIR}/put_in_stack.c \
			   ${PROGRAM_DIR}/isnt_sort.c \
			   ${PROGRAM_DIR}/sort_stacks.c \
			   ${PROGRAM_DIR}/radix.c \
			   ${PROGRAM_DIR}/actions/swap_stacks.c \
			   ${PROGRAM_DIR}/actions/push_stacks.c \
			   ${PROGRAM_DIR}/actions/rotate_stacks.c \
			   ${PROGRAM_DIR}/actions/reverse_rotate_stacks.c


#### TEST ####

ARG = 3 1 4 0 2 


#### CHECKER ####

CHECKER = checker

CHECKER_DIR = bonus

CHECKER_SRCS_OBJS = ${CHECKER_SRCS:.c=.o}

CHECKER_SRCS = ${CHECKER_DIR}/main_bonus.c \
			   ${CHECKER_DIR}/put_in_stack_bonus.c \
			   ${CHECKER_DIR}/do_instructions_bonus.c \
			   ${CHECKER_DIR}/check_stacks_bonus.c \
			   ${CHECKER_DIR}/actions/reverse_rotate_stacks_bonus.c \
			   ${CHECKER_DIR}/actions/rotate_stacks_bonus.c \
			   ${CHECKER_DIR}/actions/swap_stacks_bonus.c \
			   ${CHECKER_DIR}/actions/push_stacks_bonus.c


### COMPILATION ###

COMPILER = gcc

COMPILER_FLAGS = -Wall -Wextra -Werror

INCLUDES_DIR = includes

REMOVE = rm -rf

.c.o:
				@${COMPILER} ${COMPILER_FLAGS} -g -c $< -o ${<:.c=.o} -I ${INCLUDES_DIR} -I ${LIBFT_DIR}


#### PUSH SWAP RULES ####

${PROGRAM}:		program_compil

program_compil: compil_libft ${PROGRAM_SRCS_OBJS}
				@${COMPILER} ${COMPILER_FLAGS} ${PROGRAM_SRCS_OBJS} -I ${INCLUDES_DIR} -L ${LIBFT_DIR} -lft -o ${PROGRAM}
				@printf "The push_swap program is ready.\n"

test:			program_compil
				./${PROGRAM} ${ARG}

count:			checker_compil
				@printf "Total number of instructions : "
				./${PROGRAM} ${ARG} | wc -l

program_leaks:	program_compil
				valgrind --leak-check=full ./${PROGRAM} ${ARG}


#### LIBFT ####

LIBFT_DIR = libft

compil_libft:
				@cd ${LIBFT_DIR} && make


#### CHECKER RULES ####

${CHECKER}:		checker_compil

checker_compil:	compil_libft ${CHECKER_SRCS_OBJS}
				@${COMPILER} ${COMPILER_FLAGS} ${CHECKER_SRCS_OBJS} -I ${INCLUDES_DIR} -L ${LIBFT_DIR} -lft -g -o ${CHECKER}
				@printf "The checker is ready.\n"

checker_test:	program_compil checker_compil
				./push_swap ${ARG} | ./${CHECKER} ${ARG}

checker_leaks:	checker_compil
				valgrind ./${CHECKER} ${ARG}


#### RANDOM NUMBER GENERATOR ####

random_500:
				@seq 1 500 | sort -R | tr "\n" " "; echo

random_100:
				@seq 1 100 | sort -R | tr "\n" " "; echo

random_5:
				@seq 1 5 | sort -R | tr "\n" " "; echo

random_3:
				@seq 1 3 | sort -R | tr "\n" " "; echo


#### BOTH RULES ####

leaks:			program_compil checker_compil
				valgrind --leak-check=full ./${PROGRAM} ${ARG} | ./${CHECKER} ${ARG}

all: 			program_compil checker_compil

bonus:			all

norme:
				norminette ./srcs ./includes ./libft ./bonus
				@printf "The norm is checked in this directory and all subdirectories.\n"


#### CLEAN ####

clean:
				@cd libft && make clean
				@${REMOVE} ${PROGRAM_SRCS_OBJS}
				@${REMOVE} ${CHECKER_SRCS_OBJS}
				@printf "The object files have been deleted.\n"

fclean:			
				@cd libft && make fclean
				@${REMOVE} ${PROGRAM_SRCS_OBJS}
				@${REMOVE} ${CHECKER_SRCS_OBJS}
				@${REMOVE} ${PROGRAM}
				@${REMOVE} ${CHECKER}
				@printf "The object and binary files have been deleted.\n"

re:				fclean all

.PHONY:			clean fclean
