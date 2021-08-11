/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:27:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/11 15:37:24 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

//shift up all elements of stack a by 1.
//1 2 3 4 5 -> 2 3 4 5 1
void	ra(int *a, int stack_size)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = a[0];
	while (stack_size--)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = tmp;
}

//shift up all elements of stack b by 1.
void	rb(int *b, int stack_size)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = b[0];
	while (stack_size--)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i] = tmp;
}

//ra and rb at the same time.
void	rr(int *a, int *b, int stack_size)
{
	ra(a, stack_size);
	rb(b, stack_size);
}
