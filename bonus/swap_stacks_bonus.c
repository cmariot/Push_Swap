/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:27:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/13 12:16:49 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

//swap the first 2 elements at the top of stack a.
void	sa_checker(int *a, t_stack *stacks)
{
	int	tmp;

	if (stacks->a_size < 2)
		return ;
	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
}

//swap the first 2 elements at the top of stack b.
void	sb_checker(int *b, t_stack *stacks)
{
	int	tmp;

	if (stacks->b_size < 2)
		return ;
	tmp = b[0];
	b[0] = b[1];
	b[1] = tmp;
}

//sa and sb at the same time.
void	ss_checker(int *a, int *b, t_stack *stacks)
{
	sa_checker(a, stacks);
	sb_checker(b, stacks);
}
