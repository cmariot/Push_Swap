/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 23:49:40 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/01 15:05:57 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Compare the instructions and execute the corresponding function */
int	do_instruction(char *instr, int *a, int *b, t_stack *stacks)
{
	if (ft_strncmp(instr, "sa", (ft_strlen(instr) - 1)) == 0)
		sa_checker(a, stacks);
	else if (ft_strncmp(instr, "sb", (ft_strlen(instr) - 1)) == 0)
		sb_checker(b, stacks);
	else if (ft_strncmp(instr, "ss", (ft_strlen(instr) - 1)) == 0)
		ss_checker(a, b, stacks);
	else if (ft_strncmp(instr, "pa", (ft_strlen(instr) - 1)) == 0)
		pa_checker(a, b, stacks);
	else if (ft_strncmp(instr, "pb", (ft_strlen(instr) - 1)) == 0)
		pb_checker(a, b, stacks);
	else if (ft_strncmp(instr, "ra", (ft_strlen(instr) - 1)) == 0)
		ra_checker(a, stacks);
	else if (ft_strncmp(instr, "rb", (ft_strlen(instr) - 1)) == 0)
		rb_checker(b, stacks);
	else if (ft_strncmp(instr, "rr", (ft_strlen(instr) - 1)) == 0)
		rr_checker(a, b, stacks);
	else if (ft_strncmp(instr, "rra", (ft_strlen(instr) - 1)) == 0)
		rra_checker(a, stacks);
	else if (ft_strncmp(instr, "rrb", (ft_strlen(instr) - 1)) == 0)
		rrb_checker(b, stacks);
	else if (ft_strncmp(instr, "rrr", (ft_strlen(instr) - 1)) == 0)
		rrr_checker(a, b, stacks);
	else
		return (-1);
	return (0);
}

/* Get the instructions from the standard input */
int	get_instructions(int *a, int *b, int stack_size)
{
	char	*instruction;
	t_stack	*stacks;

	stacks = malloc(sizeof(t_stack));
	stacks->a_size = stack_size;
	stacks->b_size = 0;
	while (1)
	{
		instruction = get_next_line(0);
		if (instruction == NULL)
			break ;
		if (do_instruction(instruction, a, b, stacks) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			free(instruction);
			free(stacks);
			return (-1);
		}
		free(instruction);
	}
	free(stacks);
	return (0);
}

/* Atoi and check if the values are correctly formated */
int	ft_atoi_check(char *str, int *a, int j)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			len--;
		i++;
		if (ft_isdigit(str[i]) == 0)
			return (-1);
	}
	a[j] = ft_atoi(str);
	while (str[i])
		if (ft_isdigit(str[i++]) == 0)
			return (-1);
	if (len != ft_intlen(a[j]))
		return (-1);
	return (0);
}

/* Put the values of argv into the stack a, and 0 in stack b */
int	ft_put_in_stack(int *a, int *b, char **argv, int j)
{
	int	i;
	int	stack_size;

	stack_size = 0;
	while (argv[stack_size] != NULL)
		stack_size++;
	if (j == 0)
		stack_size--;
	i = 0;
	while (i < stack_size)
	{
		if (ft_atoi_check(argv[j++ + 1], a, i) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		b[i++] = 0;
	}
	if (check_duplication(a, stack_size) == 0)
		return (1);
	ft_putstr_fd("Error\n", 2);
	return (-1);
}
