/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:59:33 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/27 22:59:38 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "push_swap_checker.h"

int		main(int argc, char **argv);
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

#endif
