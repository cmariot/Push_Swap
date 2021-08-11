/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:31:09 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/11 16:59:24 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H

# include "libft.h"
# include <stdio.h>

int		main(int argc, char **argv);
int		ft_put_in_stack(int *a, int stack_size, char **argv);
int		get_instructions(int *a, int *b, int stack_size);
int		do_instruction(char *instr, int *a, int *b, int stack_size);
void	print_stack(int *a, char c, int stack_size);
void	sa(int *a, int stack_size);
void	sb(int *b, int stack_size);
void	ss(int *a, int *b, int stack_size);
void	pa(int *a, int *b, int stack_size);
void	pb(int *a, int *b, int stack_size);
void	ra(int *a, int stack_size);
void	rb(int *b, int stack_size);
void	rr(int *a, int *b, int stack_size);
void	rra(int *a, int stack_size);
void	rrb(int *b, int stack_size);
void	rrr(int *a, int *b, int stack_size);
int		check_stacks(int *a, int *b, int stack_size);
int		check_duplication(int *a, int stack_size);
int		ft_check_zeros(int *a, int stack_size);
int		is_sorted(int *a, int stack_size);
int		is_empty(int *b, int stack_size);

#endif
