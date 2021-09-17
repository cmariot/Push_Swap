/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isnt_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:17:34 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/17 14:11:28 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Check if the stack a is sorted, smallest to bigger */
int	isnt_sort(int *a, int stack_size)
{
	int	i;

	i = 0;
	while (i < stack_size - 1)
	{
		if (a[i] > a[i + 1])
			return (1);
		i++;
	}	
	return (0);
}
