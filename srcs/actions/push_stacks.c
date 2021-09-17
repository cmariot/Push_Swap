/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 23:01:22 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/17 16:02:23 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//take the first element at the top of b and put it at the top of a.
void	pa(int *a, int *b, t_stack *stacks)
{
	int	backup;
	int	i;
	int	j;

	if (stacks->b_size == 0)
		return ;
	backup = b[0];
	i = 0;
	while (i < (stacks->b_size - 1))
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i] = 0;
	stacks->b_size--;
	i = 0;
	j = stacks->a_size;
	while (stacks->a_size - i)
	{
		a[j] = a[j - 1];
		j--;
		i++;
	}
	a[0] = backup;
	stacks->a_size++;
	ft_putstr("pa\n");
}

//take the first element at the top of a and put it at the top of b.
void	pb(int *a, int *b, t_stack *stacks)
{
	int	backup;
	int	i;
	int	j;

	if (stacks->a_size == 0)
		return ;
	backup = a[0];
	i = 0;
	while (i < (stacks->a_size - 1))
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = 0;
	stacks->a_size--;
	i = 0;
	j = stacks->b_size;
	while (stacks->b_size - i)
	{
		b[j] = b[j - 1];
		j--;
		i++;
	}
	b[0] = backup;
	stacks->b_size++;
	ft_putstr("pb\n");
}
