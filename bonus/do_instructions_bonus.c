/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instructions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 12:13:10 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/18 12:14:19 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

/* Compare the instructions and execute the corresponding function */
int	do_instruction(char *instr, int *a, int *b, t_stack *stacks)
{
	if (ft_strcmp(instr, "sa\n") == 0)
		sa_checker(a, stacks);
	else if (ft_strcmp(instr, "sb\n") == 0)
		sb_checker(b, stacks);
	else if (ft_strcmp(instr, "ss\n") == 0)
		ss_checker(a, b, stacks);
	else if (ft_strcmp(instr, "pa\n") == 0)
		pa_checker(a, b, stacks);
	else if (ft_strcmp(instr, "pb\n") == 0)
		pb_checker(a, b, stacks);
	else if (ft_strcmp(instr, "ra\n") == 0)
		ra_checker(a, stacks);
	else if (ft_strcmp(instr, "rb\n") == 0)
		rb_checker(b, stacks);
	else if (ft_strcmp(instr, "rr\n") == 0)
		rr_checker(a, b, stacks);
	else if (ft_strcmp(instr, "rra\n") == 0)
		rra_checker(a, stacks);
	else if (ft_strcmp(instr, "rrb\n") == 0)
		rrb_checker(b, stacks);
	else if (ft_strcmp(instr, "rrr\n") == 0)
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
	int		error;

	error = 0;
	stacks = malloc(sizeof(t_stack));
	stacks->a_size = stack_size;
	stacks->b_size = 0;
	while (1)
	{
		instruction = get_next_line(0);
		if (instruction == NULL)
			break ;
		if (do_instruction(instruction, a, b, stacks) == -1)
			error++;
		free(instruction);
	}
	free(stacks);
	if (error > 0)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	return (0);
}
