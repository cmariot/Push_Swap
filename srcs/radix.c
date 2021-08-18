/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 12:41:38 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/18 17:05:40 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
int		numbers_in_max(int max)
{
	int	x;

	if (max == 10)
		return (2);
	x = 1;
	while (max > 10)
	{
		max /= 10;
		x++;
	}
	return (x);
}

int		get_max(int *a, int size)
{
	int max;

	max = a[0];
	while (size--)
	{
		if (*a > max)
			max = *a;
		a++;
	}
	return (max);
}

int		get_min(int *a, int size)
{
	int	min;

	min = a[0];
	while (size--)
	{
		if (min > *a)
			min = *a;
		a++;
	}
	return (min);
}*/

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
				a[i] = j;
			j++;
		}
		i++;
	}
	free(c);
}

void	radix(int *a, int size)
{
	ft_putstack(a, 'A', size);
	simplify_list(a, size);
	ft_putstack(a, 'A', size);
}
