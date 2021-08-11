/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:31:09 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/11 13:42:29 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H

# include "libft.h"
# include <stdio.h>

void	sa(int *a);
void	sb(int *b);
void	ss(int *a, int *b);
void	pa(int *a, int *b);
void	pb(int *a, int *b);
void	ra(int *a);
void	rb(int *b);
void	rr(int *a, int *b);
void	rra(int *a);
void	rrb(int *b);
void	rrr(int *a, int *b);
int		check_stacks(int *a, int *b, int stack_size);
int		check_duplication(int *a, int stack_size);

#endif
