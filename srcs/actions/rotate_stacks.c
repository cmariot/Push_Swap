/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:27:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/16 18:23:22 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//shift up all elements of stack a by 1.
//1 2 3 4 5 -> 2 3 4 5 1
void	ra(int *a, t_stack *stacks)
{
	int	i;
	int	backup;

	if (stacks->a_size < 2)
		return ;
	i = 0;
	backup = a[0];
	while (stacks->a_size - i)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i - 1] = backup;
	ft_putstr("ra\n");
}

//shift up all elements of stack b by 1.
void	rb(int *b, t_stack *stacks)
{
	int	i;
	int	backup;

	if (stacks->b_size < 2)
		return ;
	i = 0;
	backup = b[0];
	while (i < stacks->b_size)
	{
		if ((i + 1) < stacks->b_size)
			b[i] = b[i + 1];
		i++;
	}
	b[i - 1] = backup;
	ft_putstr("rb\n");
}

//ra and rb at the same time.
void	rr(int *a, int *b, t_stack *stacks)
{
	ra(a, stacks);
	rb(b, stacks);
}
