/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 12:27:24 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/11 16:58:58 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

//swap the first 2 elements at the top of stack a.
void	sa(int *a, int size_stack)
{
	int	tmp;

	if (size_stack < 2)
		return ;
	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
}

//swap the first 2 elements at the top of stack b.
void	sb(int *b, int size_stack)
{
	int	tmp;

	if (size_stack < 2)
		return ;
	tmp = b[0];
	b[0] = b[1];
	b[1] = tmp;
}

//sa and sb at the same time.
void	ss(int *a, int *b, int size_stack)
{
	sa(a, size_stack);
	sb(b, size_stack);
}

//take the first element at the top of b and put it at the top of a.
void	pa(int *a, int *b, int stack_size)
{
	int	i;
	int tmp;

	i = stack_size;
	tmp = a[stack_size - 1];
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
	b[i] = tmp;
}

//take the first element at the top of a and put it at the top of b.
void	pb(int *a, int *b, int stack_size)
{
	int	i;
	int tmp;

	i = stack_size;
	tmp = b[stack_size - 1];
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
	a[i] = tmp;
}
