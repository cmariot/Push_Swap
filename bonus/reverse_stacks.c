/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:27:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/11 14:38:43 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

//1 2 3 4 5 -> 2 3 4 5 1
void	ra(int *a)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = a[0];
	while (a[i + 1])
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = tmp;
}

void	rb(int *b)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = b[0];
	while (b[i + 1])
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i] = tmp;
}

void	rr(int *a, int *b)
{
	ra(a);
	rb(b);
}
