/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:32:56 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/16 22:16:14 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Create 2 int array of stack_size size, a and b */
int	create_stacks(int **a, int **b, long int stack_size)
{
	*a = malloc(sizeof(int) * stack_size);
	if (!a)
		return (-1);
	*b = malloc(sizeof(int) * stack_size);
	if (!b)
		return (-2);
	return (2);
}

/* If there is only one arg value ("") */
void	split_argv(char *str, int **a, int **b)
{
	char		**arr;
	long int	stack_size;

	arr = ft_split(str, ' ');
	if (!arr)
		return ;
	stack_size = 0;
	while (arr[stack_size])
		stack_size++;
	if (create_stacks(a, b, stack_size) != 2)
		return ;
	if (put_in_stack(*a, *b, arr, -1))
		if (isnt_sort(*a, stack_size))
			sort_stack(*a, *b, stack_size);
	ft_free_array(arr);
	ft_putstack(*a, 'A', stack_size);
}

/* Push swap's main */
int	main(int argc, char **argv)
{
	int			*a;
	int			*b;
	long int	stack_size;

	if (argc == 1)
		return (0);
	else if (argc == 2)
		split_argv(argv[1], &a, &b);
	else
	{
		stack_size = (argc - 1);
		if (create_stacks(&a, &b, stack_size) != 2)
			return (-1);
		if (put_in_stack(a, b, argv, 0))
			if (isnt_sort(a, stack_size))
				sort_stack(a, b, stack_size);
		ft_putstack(a, 'A', stack_size);
	}
	free(a);
	free(b);
	return (0);
}
