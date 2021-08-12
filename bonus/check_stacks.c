/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:17:34 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/12 14:21:12 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

int	ft_check_zeros(int *a, int stack_size)
{
	int	i;
	int	zero;

	zero = 0;
	i = 0;
	while (stack_size--)
	{
		if (a[i] == 0)
			zero++;
		i++;
	}
	if (zero > 1)
	{
		return (-1);
	}
	return (zero);
}

int	check_duplication(int *a, int stack_size)
{
	int	i;
	int	j;
	int	zero;

	i = 0;
	zero = ft_check_zeros(a, stack_size);
	if (zero > 1 || zero == -1)
	{
		return (-1);
	}
	while (a[i + 1])
	{
		j = i + 1;
		while (j <= stack_size)
		{
			if (a[i] == a[j])
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	is_empty(int *b, int stack_size)
{
	int	i;

	i = 0;
	while (i != stack_size)
	{
		if (b[i] != '\0')
			return (-1);
		i++;
	}
	return (0);
}

int	is_sorted(int *a, int stack_size)
{
	int	i;
	int	check_zero;

	check_zero = ft_check_zeros(a, stack_size);
	i = 0;
	while (a[i] < 0)
	{
		if (a[i] >= a[i + 1])
			return (-1);
		stack_size--;
		i++;
	}	
	if (check_zero == 1 && a[i] != 0)
	{
		return (-1);
	}
	while ((stack_size-- - 1) && (a[i + 1] != '\0'))
	{
		if (a[i] >= a[i + 1])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

int	check_stacks(int *a, int *b, int stack_size)
{
	int	size;

	size = stack_size;
	if (is_empty(b, stack_size) == -1)
	{
		ft_putstr_fd("\nKO\nThe stack B is not empty.\n", 1);
	}
	else if (is_sorted(a, size) == -1)
	{
		ft_putstr_fd("\nKO\nThe stack A is not sorted.\n", 1);
	}
	else
	{
		ft_putstr_fd("\nOK\n", 1);
	}
	return (0);
}
