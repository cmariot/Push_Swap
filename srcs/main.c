/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:53:13 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/12 19:00:49 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		stack_size;
	int		*a;
	int		*b;

	if (argc == 1)
		return (0);
	stack_size = (argc - 1);
	a = malloc(sizeof(int) * stack_size);
	b = malloc(sizeof(int) * stack_size);
	if (!a || !b)
		return (-1);
	if (ft_put_in_stack(a, b, stack_size, argv) == 1)
	{
		if (is_sorted(a, stack_size) == -1)
		{
			ft_putstack(a, 'A', stack_size);
			ft_putstack(b, 'B', stack_size);
		}
	}
	free(a);
	free(b);
	return (0);
}
