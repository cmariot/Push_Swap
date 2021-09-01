/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stacks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:44:19 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/01 15:12:42 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//take the first element at the top of b and put it at the top of a.
void	pa_checker(int *a, int *b, t_stack *stacks)
{
	int	backup;
	int	i;
	int	j;

	if (stacks->b_size == 0)
		return ;
	backup = b[0];
	i = 0;
	while (stacks->b_size - i)
	{
		b[i] = b[i + 1];
		i++;
	}
	stacks->b_size--;
	b[i - 1] = 0;
	i = 0;
	j = stacks->a_size;
	while (stacks->a_size - i)
	{
		a[j] = a[j - 1];
		i++;
		j--;
	}
	a[0] = backup;
	stacks->a_size++;
}

//take the first element at the top of a and put it at the top of b.
void	pb_checker(int *a, int *b, t_stack *stacks)
{
	int	backup;
	int	i;
	int	j;

	if (stacks->a_size == 0)
		return ;
	backup = a[0];
	i = 0;
	while (stacks->a_size - i)
	{
		a[i] = a[i + 1];
		i++;
	}
	stacks->a_size--;
	a[i - 1] = 0;
	i = 0;
	j = stacks->b_size;
	while (stacks->b_size - i)
	{
		b[j] = b[j - 1];
		i++;
		j--;
	}
	b[0] = backup;
	stacks->b_size++;
}
