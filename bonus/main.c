/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:40:40 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/13 15:03:39 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	parse_argv(char *str)
{
	char	**arr;
	int		stack_size;
	int		*a;
	int		*b;

	arr = ft_split(str, ' ');
	if (arr == NULL)
		return ;
	stack_size = 0;
	while (arr[stack_size])
		stack_size++;
	a = malloc(sizeof(int) * stack_size);
	if (!a)
		return ;
	b = malloc(sizeof(int) * stack_size);
	if (!b)
		return ;
	if (ft_put_in_stack(a, b, arr, -1) == 1)
		if (get_instructions(a, b, stack_size) != -1)
			check_stacks(a, b, stack_size);
	free(a);
	free(b);
	free(arr);
}

int	main(int argc, char **argv)
{
	int		stack_size;
	int		*a;
	int		*b;

	if (argc == 1)
		return (0);
	else if (argc == 2)
		parse_argv(argv[1]);
	else
	{
		stack_size = (argc - 1);
		a = malloc(sizeof(int) * stack_size);
		if (!a)
			return (-1);
		b = malloc(sizeof(int) * stack_size);
		if (!b)
			return (-1);
		if (ft_put_in_stack(a, b, argv, 0) == 1)
			if (get_instructions(a, b, stack_size) != -1)
				check_stacks(a, b, stack_size);
		free(a);
		free(b);
	}
	return (0);
}
