/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 14:53:13 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/13 10:25:12 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(int *a, int *b, int stack_size)
{
	t_stack	*stacks;

	stacks = malloc(sizeof(t_stack));
	if (!stacks)
		return ;
	stacks->a_size = stack_size;
	stacks->b_size = 0;
	if (stack_size == 2)
		ft_putstr("ra\n");
	a[0] = 0;
	b[0] = 0;
	free(stacks);
}

void	split_argv(char *str)
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
		if (is_sorted(a, stack_size) == -1)
			sort_stack(a, b, stack_size);
	free(a);
	free(b);
	free(arr);
}

int	main(int argc, char **argv)
{
	int		*a;
	int		*b;
	int		stack_size;

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
