/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:27:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/11 13:29:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	sa(int *a)
{
	int	tmp;

	if (!a[0] || !a[1])
		return ;
	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
}

void	sb(int *b)
{
	int	tmp;

	if (!b[0] || !b[1])
		return ;
	tmp = b[0];
	b[0] = b[1];
	b[1] = tmp;
}

void	ss(int *a, int *b)
{
	sa(a);
	sb(b);
}

void	pa(int *a, int *b)
{
	int	i;

	if (!b[0])
		return ;
	i = 0;
	while (a[i])
		i++;
	while (i)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = b[0];
	i = 0;
	while (b[i + 1])
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i] = '\0';
}

void	pb(int *a, int *b)
{
	int	i;

	if (!a[0])
		return ;
	i = 0;
	while (b[i])
		i++;
	while (i)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = a[0];
	i = 0;
	while (a[i + 1])
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = '\0';
}
