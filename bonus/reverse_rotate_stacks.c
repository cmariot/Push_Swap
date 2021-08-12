/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stacks.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:27:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/12 20:55:21 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

//shift down all elements of stack a by 1.
//1 2 3 4 5 -> 5 1 2 3 4
void	rra(int *a, t_stack *stacks)
{
	int	i;
	int	backup;

	if (stacks->a_size < 2)
		return ;
	i = stacks->a_size - 1;
	backup = a[i];
	while (i != 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = backup;
}

//shift down all elements of stack b by 1.
void	rrb(int *b, t_stack *stacks)
{
	int	i;
	int	backup;

	if (stacks->b_size < 2)
		return ;
	i = stacks->b_size - 1;
	backup = b[i];
	while (i != 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = backup;
}

//rra and rrb at the same time.
void	rrr(int *a, int *b, t_stack *stacks)
{
	rra(a, stacks);
	rrb(b, stacks);
}
