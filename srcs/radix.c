/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:41:38 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/23 19:06:56 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_tab(int *tab, int size)
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
			if (tab[i] > tab[i + j])
			{
				stock = tab[i];
				tab[i] = tab[i + j];
				tab[i + j] = stock;
			}
			j++;
		}
		i++;
	}
}

int	*copy_tab(int *a, int size)
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

void	simplify_list(int *a, int size)
{
	int	*c;
	int	i;
	int	j;

	c = copy_tab(a, size);
	ft_sort_tab(c, size);
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

void	radix(int *a, int *b, int size, t_stack *stacks)
{
	int	max_binary_bits;
	int	i;
	int	j;

	simplify_list(a, size);
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
