/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 23:49:40 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/11 14:38:22 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

int	do_instruction(char *instr, int *a, int *b)
{
	if (ft_strncmp(instr, "sa", (ft_strlen(instr) - 1)) == 0)
		sa(a);
	else if (ft_strncmp(instr, "sb", (ft_strlen(instr) - 1)) == 0)
		sb(b);
	else if (ft_strncmp(instr, "ss", (ft_strlen(instr) - 1)) == 0)
		ss(a, b);
	else if (ft_strncmp(instr, "pa", (ft_strlen(instr) - 1)) == 0)
		pa(a, b);
	else if (ft_strncmp(instr, "pb", (ft_strlen(instr) - 1)) == 0)
		pb(a, b);
	else if (ft_strncmp(instr, "ra", (ft_strlen(instr) - 1)) == 0)
		ra(a);
	else if (ft_strncmp(instr, "rb", (ft_strlen(instr) - 1)) == 0)
		rb(b);
	else if (ft_strncmp(instr, "rr", (ft_strlen(instr) - 1)) == 0)
		rr(a, b);
	else if (ft_strncmp(instr, "rra", (ft_strlen(instr) - 1)) == 0)
		rra(a);
	else if (ft_strncmp(instr, "rrb", (ft_strlen(instr) - 1)) == 0)
		rrb(b);
	else if (ft_strncmp(instr, "rrr", (ft_strlen(instr) - 1)) == 0)
		rrr(a, b);
	else
		return (-1);
	return (0);
}

int	get_instructions(int *a, int *b)
{
	char	*instruction;

	while (1)
	{
		instruction = get_next_line(1);
		if (!instruction)
			break ;
		if (do_instruction(instruction, a, b) == -1)
		{
			ft_putstr_fd("Error\nInvalid instruction.\n", 2);
			return (-1);
		}
		free(instruction);
	}
	return (1);
}

int	ft_put_in_stack(int *a, int stack_size, char **argv)
{
	int	i;
	int	size;

	i = 0;
	size = stack_size;
	while (stack_size--)
	{
		a[i] = ft_atoi(argv[i + 1]);
		if (ft_strlen(argv[i + 1]) != ft_intlen(a[i]))
		{
			if (*argv[i + 1] != '0')
			{
				ft_putstr_fd("Error\nInvalid argument.\n", 2);
				return (-1);
			}
		}
		i++;
	}
	if (check_duplication(a, size) == -1)
	{
		ft_putstr_fd("Error\nDuplication.\n", 2);
		return (-1);
	}
	return (1);
}

void	print_stack(int *a, char c, int stack_size)
{
	int	i;

	printf("\n --- Stack %c ---\n", c);
	i = 0;
	while (stack_size--)
	{
		printf("%c[%d] = %10d\n", c, i, a[i]);
		i++;
	}
}

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
	if (ft_put_in_stack(a, stack_size, argv) == 1)
	{
		if (get_instructions(a, b) == 1)
		{
			check_stacks(a, b, stack_size);
			print_stack(a, 'a', stack_size);
			print_stack(b, 'b', stack_size);
		}
	}
	free(a);
	free(b);
	return (0);
}
