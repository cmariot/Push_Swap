/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 23:49:40 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/12 14:36:44 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

int	do_instruction(char *instr, int *a, int *b, t_stack *stacks)
{
	if (ft_strncmp(instr, "sa", (ft_strlen(instr) - 1)) == 0)
		sa(a, stacks);
	else if (ft_strncmp(instr, "sb", (ft_strlen(instr) - 1)) == 0)
		sb(b, stacks);
	else if (ft_strncmp(instr, "ss", (ft_strlen(instr) - 1)) == 0)
		ss(a, b, stacks);
	else if (ft_strncmp(instr, "pa", (ft_strlen(instr) - 1)) == 0)
		pa(a, b, stacks);
	else if (ft_strncmp(instr, "pb", (ft_strlen(instr) - 1)) == 0)
		pb(a, b, stacks);
	else if (ft_strncmp(instr, "ra", (ft_strlen(instr) - 1)) == 0)
		ra(a, stacks);
	else if (ft_strncmp(instr, "rb", (ft_strlen(instr) - 1)) == 0)
		rb(b, stacks);
	else if (ft_strncmp(instr, "rr", (ft_strlen(instr) - 1)) == 0)
		rr(a, b, stacks);
	else if (ft_strncmp(instr, "rra", (ft_strlen(instr) - 1)) == 0)
		rra(a, stacks);
	else if (ft_strncmp(instr, "rrb", (ft_strlen(instr) - 1)) == 0)
		rrb(b, stacks);
	else if (ft_strncmp(instr, "rrr", (ft_strlen(instr) - 1)) == 0)
		rrr(a, b, stacks);
	else
		return (-1);
	return (0);
}

int	get_instructions(int *a, int *b, int stack_size)
{
	char	*instruction;
	t_stack	*stacks;

	stacks = malloc(sizeof(t_stack));
	stacks->a_size = stack_size;
	stacks->b_size = 0;
	while (1)
	{
		instruction = get_next_line(1);
		if (!instruction)
			break ;
		if (do_instruction(instruction, a, b, stacks) == -1)
		{
			ft_putstr_fd("Error\nInvalid instruction.\n", 2);
			return (-1);
		}
		free(instruction);
	}
	free(stacks);
	return (0);
}

int	ft_put_in_stack(int *a, int *b, int stack_size, char **argv)
{
	int	i;

	i = 0;
	while (stack_size - i)
	{
		if (*argv[i + 1] == '\0')
		{
			ft_putstr_fd("Error\nNULL argument.\n", 2);
			return (-1);
		}
		a[i] = ft_atoi(argv[i + 1]);
		b[i] = 0;
		if (ft_strlen(argv[i + 1]) != ft_intlen(a[i]) && *argv[i + 1] != '0')
		{
			ft_putstr_fd("Error\nInvalid argument.\n", 2);
			return (-1);
		}
		i++;
	}
	if (check_duplication(a, stack_size) != -1)
		return (1);
	ft_putstr_fd("Error\nDuplication.\n", 2);
	return (-1);
}

void	print_stack(int *a, char c, int stack_size)
{
	int	i;
	int	len;

	ft_putstr_fd("\n --- Stack ", 1);
	ft_putchar_fd(c, 1);
	ft_putstr_fd(" ---\n", 1);
	i = 0;
	len = 0;
	while (stack_size--)
	{
		ft_putchar_fd(c, 1);
		ft_putchar_fd('[', 1);
		ft_putnbr_fd(i, 1);
		ft_putstr_fd("] = ", 1);
		len = ft_intlen(a[i]);
		while (len++ != 11)
			ft_putchar_fd(' ', 1);
		ft_putnbr_fd(a[i], 1);
		ft_putchar_fd('\n', 1);
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
	if (ft_put_in_stack(a, b, stack_size, argv) == 1)
	{
		if (get_instructions(a, b, stack_size) != -1)
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
