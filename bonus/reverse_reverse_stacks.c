/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_reverse_stacks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:27:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/11 14:36:25 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

//1 2 3 4 5 -> 5 1 2 3 4
void	rra(int *a)
{
	int	i;
	int	tmp;

	i = 0;
	if (!a[i])
		return ;
	while (a[i])
		i++;
	i--;
	tmp = a[i];
	while (i != 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = tmp;
}

void	rrb(int *b)
{
	int	i;
	int	tmp;

	i = 0;
	if (!b[i])
		return ;
	while (b[i])
		i++;
	i--;
	tmp = b[i];
	while (i != 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = tmp;
}

void	rrr(int *a, int *b)
{
	rra(a);
	rrb(b);
}
