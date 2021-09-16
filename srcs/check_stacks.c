/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:17:34 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/16 15:48:08 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Check if there is more than one 0 in the stack a */
int	ft_check_zeros(int *a, int stack_size)
{
	int	i;
	int	zero;

	zero = 0;
	i = 0;
	while (stack_size--)
		if (a[i++] == 0)
			zero++;
	if (zero > 1)
		return (-1);
	return (zero);
}

/* Check if there are duplicate numbers in the stack a*/
int	check_duplication(int *a, int stack_size)
{
	int	i;
	int	j;
	int	zero;

	i = 0;
	zero = ft_check_zeros(a, stack_size);
	if (zero > 1 || zero == -1)
		return (-1);
	while (i < stack_size)
	{
		j = i + 1;
		while (j < stack_size)
		{
			if (a[i] == a[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

/* Check if the stack a is sorted, smallest to bigger */
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
		return (-1);
	while ((stack_size-- - 1) && (a[i + 1] != '\0'))
	{
		if (a[i] >= a[i + 1])
			return (-1);
		i++;
	}
	return (0);
}
