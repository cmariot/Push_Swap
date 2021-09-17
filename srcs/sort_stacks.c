/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:32:07 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/17 14:10:18 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Bubble sort to get the median, aka the third value */
int	get_median(int *a, int size)
{
	int	*stack_copy;
	int	median;

	stack_copy = copy_stack(a, size);
	bubble_sort(stack_copy, size);
	median = stack_copy[2];
	free(stack_copy);
	return (median);
}

/* For three numbers : 10 instructions max */
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
	if (isnt_sort(a, stacks->a_size))
		sort_three(a, stacks);
	if (b[0] < b[1])
		sb(b, stacks);
	pa(a, b, stacks);
	pa(a, b, stacks);
}

/* For three numbers : 2 instructions max 
	2 1 3
	3 2 1
	3 1 2
	1 3 2
	2 3 1  */
void	sort_three(int *a, t_stack *stacks)
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
			rra(a, stacks);
			sa(a, stacks);
		}
		else
			rra(a, stacks);
	}
}

/* Choose the correct algorithm depending a_size */
void	choose_algorithm(int *a, int *b, t_stack *stacks)
{
	if (stacks->a_size == 2)
		ra(a, stacks);
	else if (stacks->a_size == 3)
		sort_three(a, stacks);
	else if (stacks->a_size == 5)
		sort_five(a, b, stacks);
	else
		radix(a, b, stacks->a_size, stacks);
}

/* Create the stack size structure and chose algorithm */
void	sort_stack(int *a, int *b, int stack_size)
{
	t_stack	*stacks;

	stacks = malloc(sizeof(t_stack));
	if (!stacks)
		return ;
	stacks->a_size = stack_size;
	stacks->b_size = 0;
	choose_algorithm(a, b, stacks);
	free(stacks);
}
