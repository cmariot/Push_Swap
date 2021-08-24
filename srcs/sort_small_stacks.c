/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:32:07 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/24 13:41:10 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* For three numbers : 3 instructions max */
void	sort_three(int *a, int *b, t_stack *stacks)
{
	if (a[0] > a[1])
	{
		if (a[2] > a[0])
			sa(a, stacks);
		else if (a[2] > a[1])
			ra(a, stacks);
		else
		{
			sa(a, stacks);
			rra(a, stacks);
		}
	}
	else
	{
		if (a[2] > a[0])
		{
			pb(a, b, stacks);
			ra(a, stacks);
			pa(a, b, stacks);
		}
		else
			rra(a, stacks);
	}
}

/* For three numbers : XX instructions max */
void	sort_five(int *a, int *b, t_stack *stacks)
{
	pb(a, b, stacks);
	pb(a, b, stacks);
	sort_three(a, b, stacks);
	pa(a, b, stacks);
	pa(a, b, stacks);
}
