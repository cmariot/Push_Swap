/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:32:07 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/26 02:06:36 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* For three numbers : 3 instructions max */
void	sort_three(int *a, int *b, t_stack *stacks)
{
	if (a[0] > a[1])
	{
		if (a[2] > a[0])
			sa(a, stacks);
		else if (a[2] > a[1])
			ra(a, stacks);
		else
		{
			sa(a, stacks);
			rra(a, stacks);
		}
	}
	else if (a[0] < a[1])
	{
		if (a[2] > a[0])
		{
			pb(a, b, stacks);
			ra(a, stacks);
			pa(a, b, stacks);
		}
		else
			rra(a, stacks);
	}
}

/* Bubble sort to get the median, aka the third value */
int	get_median(int *a, int size)
{
	int	*stack_copy;
	int	median;

	stack_copy = copy_stack(a, size);
	ft_sort_stack(stack_copy, size);
	median = stack_copy[2];
	free(stack_copy);
	return (median);
}

/* For three numbers : 11 instructions max */
void	sort_five(int *a, int *b, t_stack *stacks)
{
	int	median;

	median = get_median(a, stacks->a_size);
	while (stacks->a_size != 3)
	{
		if (a[0] < median)
			pb(a, b, stacks);
		else
			ra(a, stacks);
	}
	if (is_sorted(a, stacks->a_size) == -1)
		sort_three(a, b, stacks);
	if (b[0] < b[1])
		sb(b, stacks);
	pa(a, b, stacks);
	pa(a, b, stacks);
}
