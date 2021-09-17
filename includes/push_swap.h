/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:59:33 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/16 22:47:06 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int	a_size;
	int	b_size;
}	t_stack;

//Parsing
int		create_stacks(int **a, int **b, long int stack_size);
int		put_in_stack(int *a, int *b, char **argv, int argv_counter);
int		*copy_stack(int *a, int size);
int		check_stacks(int *a, int *b, int stack_size);
int		check_duplication(int *a, int stack_size);
int		check_zeros(int *a, int stack_size);
int		is_empty(int *b, int stack_size);
int		isnt_sort(int *a, int stack_size);

//Sorting Algorithms
void	sort_stack(int *a, int *b, int stack_size);
void	bubble_sort(int *stack, int size);
void	sort_three(int *a, t_stack *stacks);
void	sort_five(int *a, int *b, t_stack *stacks);
void	radix(int *a, int *b, int size, t_stack *stacks);

//Push Swap actions
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

#endif
