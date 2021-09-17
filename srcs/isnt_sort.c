/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isnt_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:17:34 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/16 22:43:15 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Check if the stack a is sorted, smallest to bigger */
int	isnt_sort(int *a, int stack_size)
{
	int	i;
	int	check_zero;

	i = 0;
	check_zero = check_zeros(a, stack_size);
	while (a[i] < 0)
	{
		if (a[i] >= a[i + 1])
			return (0);
		stack_size--;
		i++;
	}	
	if (check_zero == 1 && a[i] != 0)
		return (-1);
	while ((stack_size-- - 1) && (a[i + 1] != '\0'))
	{
		if (a[i] >= a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
