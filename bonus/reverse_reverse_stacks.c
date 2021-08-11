/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_reverse_stacks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:27:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/11 15:38:11 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

//shift down all elements of stack a by 1.
//1 2 3 4 5 -> 5 1 2 3 4
void	rra(int *a, int stack_size)
{
	int	i;
	int	tmp;

	if (!a[0])
		return ;
	i = stack_size - 1;
	tmp = a[i];
	while (i != 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = tmp;
}

//shift down all elements of stack b by 1.
void	rrb(int *b, int stack_size)
{
	int	i;
	int	tmp;

	if (!b[0])
		return ;
	i = stack_size - 1;
	tmp = b[i];
	while (i != 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = tmp;
}

//rra and rrb at the same time.
void	rrr(int *a, int *b, int stack_size)
{
	rra(a, stack_size);
	rrb(b, stack_size);
}
