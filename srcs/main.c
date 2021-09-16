/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 11:32:56 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/16 15:48:00 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Choose the correct algorithm depending a_size */
void	choose_algorithm(int *a, int *b, t_stack *stacks)
{
	if (stacks->a_size == 2)
		ra(a, stacks);
	else if (stacks->a_size == 3)
		sort_three(a, b, stacks);
	else if (stacks->a_size == 5)
		sort_five(a, b, stacks);
	else
		radix(a, b, stacks->a_size, stacks);
}

/* Create the stack size structure and chose algorithm */
void	sort_stack(int *a, int *b, int stack_size)
{
	t_stack	*stacks;

	stacks = malloc(sizeof(t_stack));
	if (!stacks)
		return ;
	stacks->a_size = stack_size;
	stacks->b_size = 0;
	choose_algorithm(a, b, stacks);
	free(stacks);
}

/* If there is only one arg value ("") */
void	split_argv(char *str)
{
	char		**arr;
	long int	stack_size;
	int			*a;
	int			*b;

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
		if (is_sorted(a, stack_size) == -1)
			sort_stack(a, b, stack_size);
	free(a);
	free(b);
	ft_free_array(arr);
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
		split_argv(argv[1]);
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
			if (is_sorted(a, stack_size) == -1)
				sort_stack(a, b, stack_size);
		free(a);
		free(b);
	}
	return (0);
}
