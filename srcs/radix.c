/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:41:38 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/23 22:03:49 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Bubble sort algorithm */
void	ft_sort_stack(int *stack, int size)
{
	int	i;
	int	j;
	int	stock;

	i = 0;
	stock = 0;
	while (i < size)
	{
		j = 0;
		while (j < (size - i))
		{
			if (stack[i] > stack[i + j])
			{
				stock = stack[i];
				stack[i] = stack[i + j];
				stack[i + j] = stock;
			}
			j++;
		}
		i++;
	}
}

/* Create a copy of stack a */
int	*copy_stack(int *a, int size)
{
	int	*c;
	int	i;

	c = malloc(sizeof(int) * size);
	if (!c)
		return (NULL);
	i = 0;
	while (size--)
	{
		c[i] = a[i];
		i++;
	}
	return (c);
}

/* The min number will be 0, the max will be N (positive numbers) */
void	simplify_stack(int *a, int size)
{
	int	*c;
	int	i;
	int	j;

	c = copy_stack(a, size);
	ft_sort_stack(c, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (a[i] == c[j])
			{
				a[i] = j;
				j++;
				break ;
			}
			j++;
		}
		i++;
	}
	free(c);
}

/* Radix algorithm work for [0;N) interval, 
 * First we need to simplify the a stack ;
 * We compare the last number : if its 1 we ra, in other case we pb
 * Finaly we put all the numbers in a and do it for all the bits */
void	radix(int *a, int *b, int size, t_stack *stacks)
{
	int	max_binary_bits;
	int	i;
	int	j;

	simplify_stack(a, size);
	max_binary_bits = 0;
	while (((size - 1) >> max_binary_bits) != 0)
		max_binary_bits++;
	i = 0;
	while (i < max_binary_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a[0] >> i) & 1) == 1)
				ra(a, stacks);
			else
				pb(a, b, stacks);
			j++;
		}
		while (stacks->b_size)
			pa(a, b, stacks);
		i++;
	}
}
