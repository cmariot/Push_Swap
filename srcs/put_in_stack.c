/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 23:49:40 by cmariot           #+#    #+#             */
/*   Updated: 2021/09/16 22:42:46 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Check if there is more than one 0 in the stack a */
int	check_zeros(int *a, int stack_size)
{
	int	i;
	int	zero;

	zero = 0;
	i = 0;
	while (stack_size--)
		if (a[i++] == 0)
			zero++;
	if (zero > 1)
		return (-1);
	return (zero);
}

/* Check if there are duplicate numbers in the stack a*/
int	check_duplication(int *a, int stack_size)
{
	int	i;
	int	j;
	int	zero;

	i = 0;
	zero = check_zeros(a, stack_size);
	if (zero > 1 || zero == -1)
		return (-1);
	while (i < stack_size)
	{
		j = i + 1;
		while (j < stack_size)
		{
			if (a[i] == a[j])
				return (-1);
			j++;
		}
		i++;
	}
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
int	put_in_stack(int *a, int *b, char **argv, int argv_counter)
{
	int	i;
	int	stack_size;

	stack_size = 0;
	while (argv[stack_size] != NULL)
		stack_size++;
	if (argv_counter == 0)
		stack_size--;
	i = 0;
	while (i < stack_size)
	{
		if (ft_atoi_check(argv[argv_counter++ + 1], a, i) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		b[i++] = 0;
	}
	if (check_duplication(a, stack_size) == 0)
		return (1);
	ft_putstr_fd("Error\n", 2);
	return (0);
}
