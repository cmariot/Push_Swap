/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stacks_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:27:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/17 14:23:26 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//shift down all elements of stack a by 1.
//1 2 3 4 5 -> 5 1 2 3 4
void	rra_checker(int *a, t_stack *stacks)
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
void	rrb_checker(int *b, t_stack *stacks)
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
void	rrr_checker(int *a, int *b, t_stack *stacks)
{
	rra_checker(a, stacks);
	rrb_checker(b, stacks);
}
