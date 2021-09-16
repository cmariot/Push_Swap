/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:59:33 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/16 16:12:40 by cmariot          ###   ########.fr       */
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
void	sort_three(int *a, int *b, t_stack *stacks);
void	sort_five(int *a, int *b, t_stack *stacks);
void	radix(int *a, int *b, int size, t_stack *stacks);
void	ft_sort_stack(int *stack, int size);
int		*copy_stack(int *a, int size);
int		ft_put_in_stack(int *a, int *b, char **argv, int i);
int		check_stacks(int *a, int *b, int stack_size);
int		check_duplication(int *a, int stack_size);
int		ft_check_zeros(int *a, int stack_size);
int		is_sorted(int *a, int stack_size);
int		is_empty(int *b, int stack_size);

#endif
