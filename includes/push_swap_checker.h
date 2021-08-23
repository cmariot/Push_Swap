/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:31:09 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/23 14:31:16 by cmariot          ###   ########.fr       */
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
int		ft_put_in_stack(int *a, int *b, char **argv, int i);
int		get_instructions(int *a, int *b, int stack_size);
int		do_instruction(char *instr, int *a, int *b, t_stack *stacks);
void	print_stack(int *a, char c, int stack_size);
void	sa_checker(int *a, t_stack *stacks);
void	sb_checker(int *b, t_stack *stacks);
void	ss_checker(int *a, int *b, t_stack *stacks);
void	pa_checker(int *a, int *b, t_stack *stacks);
void	pb_checker(int *a, int *b, t_stack *stacks);
void	ra_checker(int *a, t_stack *stacks);
void	rb_checker(int *b, t_stack *stacks);
void	rr_checker(int *a, int *b, t_stack *stacks);
void	rra_checker(int *a, t_stack *stacks);
void	rrb_checker(int *b, t_stack *stacks);
void	rrr_checker(int *a, int *b, t_stack *stacks);
int		check_stacks(int *a, int *b, int stack_size);
int		check_duplication(int *a, int stack_size);
int		ft_check_zeros(int *a, int stack_size);
int		is_sorted(int *a, int stack_size);
int		is_empty(int *b, int stack_size);

#endif
