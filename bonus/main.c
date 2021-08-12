/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:40:40 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/12 21:08:32 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

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
		if (get_instructions(a, b, stack_size) != -1)
			check_stacks(a, b, stack_size);
	ft_putstack(a, 'A', stack_size);
	ft_putstack(b, 'B', stack_size);
	free(a);
	free(b);
	return (0);
}
