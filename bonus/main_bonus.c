/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:40:40 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/18 12:29:41 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

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
void	parse_argv(char *str, int **a, int **b)
{
	char	**arr;
	int		stack_size;

	arr = ft_split(str, ' ');
	if (arr == NULL)
		return ;
	stack_size = 0;
	while (arr[stack_size])
		stack_size++;
	if (create_stacks(a, b, stack_size) != 2)
		return ;
	if (put_in_stack(*a, *b, arr, -1) == 1)
		if (get_instructions(*a, *b, stack_size) != -1)
			check_stacks(*a, *b, stack_size);
	ft_free_array(arr);
}

/* Push swap checker's main */
int	main(int argc, char **argv)
{
	int		stack_size;
	int		*a;
	int		*b;

	if (argc == 1)
		return (0);
	else if (argc == 2)
		parse_argv(argv[1], &a, &b);
	else
	{
		stack_size = (argc - 1);
		if (create_stacks(&a, &b, stack_size) != 2)
			return (-1);
		if (put_in_stack(a, b, argv, 0) == 1)
			if (get_instructions(a, b, stack_size) != -1)
				check_stacks(a, b, stack_size);
	}
	free(a);
	free(b);
	return (0);
}
