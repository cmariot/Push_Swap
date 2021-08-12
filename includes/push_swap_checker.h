/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:31:09 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/12 12:48:59 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H

# include "libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int	a_size;
	int	b_size;
}	t_stack;

int		main(int argc, char **argv);
int		ft_put_in_stack(int *a, int *b, int stack_size, char **argv);
int		get_instructions(int *a, int *b, int stack_size);
int		do_instruction(char *instr, int *a, int *b, t_stack *stacks);
void	print_stack(int *a, char c, int stack_size);
void	sa(int *a, t_stack *stacks);
void	sb(int *b, t_stack *stacks);
void	ss(int *a, int *b, t_stack *stacks);
void	pa(int *a, int *b, t_stack *stacks);
void	pb(int *a, int *b, t_stack *stacks);
void	ra(int *a, t_stack *stacks);
void	rb(int *b, t_stack *stacks);
void	rr(int *a, int *b, t_stack *stacks);
void	rra(int *a, t_stack *stacks);
void	rrb(int *b, t_stack *stacks);
void	rrr(int *a, int *b, t_stack *stacks);
int		check_stacks(int *a, int *b, int stack_size);
int		check_duplication(int *a, int stack_size);
int		ft_check_zeros(int *a, int stack_size);
int		is_sorted(int *a, int stack_size);
int		is_empty(int *b, int stack_size);

#endif
